/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc058/submissions/71718348
 * Submitted at: 2025-12-14 15:44:52
 * Problem URL: https://atcoder.jp/contests/ahc058/tasks/ahc058_a
 * Result: AC
 * Execution Time: 1757 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

namespace utility {
  struct timer {
    chrono::high_resolution_clock::time_point start;
    void CodeStart() { start = chrono::high_resolution_clock::now(); }
    double elapsedMs() const {
      using namespace std::chrono;
      return (double)duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    }
  } mytm;
}

// ---------------------------------------------------------

struct Trace {
  int i, j;       // (-1, -1) は何もしない
  int parent_id;
  Trace() : i(-1), j(-1), parent_id(-1) {}
  Trace(int _i, int _j, int _p) : i(_i), j(_j), parent_id(_p) {}
};

static vector<Trace> traces;

// ---------------------------------------------------------

struct State {
  int trace_id;
  long double apples;
  double B[4][10];
  int P[4][10];
  long double score;

  State() : trace_id(-1), apples(0), score(0) {
    rep(i, 4) rep(j, 10) {
      B[i][j] = 1.0;
      P[i][j] = 0;
    }
  }
};

struct Params {
  // 1回のビームで使う幅（元より少し強め）
  int bwEarly = 900;
  int bwMid   = 600;
  int bwLate  = 380;
  int bwEnd   = 200;

  int guaranteeEarly = 2;
  int guaranteeLate  = 1;

  // 展開候補の絞り込み（ratio/gain上位 + 少しランダム追加）
  int kr = 12;
  int kg = 7;
  int randomExtra = 4;

  // ランダム性（同点付近の揺らぎ）
  double noiseRatio = 0.015;
  double noiseGain  = 0.010;

  // 時間ギリのときの安全マージン
  double safetyMs = 250.0;

  // traces reserve
  int traceReserve = 9000000;
};

struct Solver {
  int N, L, T;
  long long K;
  vector<int> A;
  vector<vector<long long>> C;

  static constexpr long double APPLE_CAP = 1e300L;
  static constexpr double B_CAP = 1e200;

  Solver() {
    input();
  }

  void input() {
    cin >> N >> L >> T >> K;
    A.resize(N);
    rep(j, N) cin >> A[j];
    C.assign(L, vector<long long>(N));
    rep(i, L) rep(j, N) cin >> C[i][j];
  }

  static inline void clampApple(long double &x) {
    if (x > APPLE_CAP) x = APPLE_CAP;
    if (x < -APPLE_CAP) x = -APPLE_CAP;
  }
  static inline void clampB(double &x) {
    if (x > B_CAP) x = B_CAP;
    if (x < -B_CAP) x = -B_CAP;
  }

  inline void process_production(State &s) const {
    // Level 0
    rep(j, N) {
      if (s.P[0][j] == 0) continue;
      long double add = (long double)A[j] * (long double)s.B[0][j] * (long double)s.P[0][j];
      s.apples += add;
    }
    clampApple(s.apples);

    // Level 1..3
    for (int i = 1; i < L; i++) {
      rep(j, N) {
        if (s.P[i][j] == 0) continue;
        double prod = s.B[i][j] * (double)s.P[i][j];
        s.B[i - 1][j] += prod;
        clampB(s.B[i - 1][j]);
      }
    }
  }

  // 「今のPのまま、もう強化しない」前提で残りRターンの最終りんごを閉形式で予測
  inline long double project_no_more_upgrades(const State &s, int R) const {
    if (R <= 0) return s.apples;

    long double res = s.apples;
    long double r = (long double)R;

    long double S1 = r * (r - 1.0L) / 2.0L;                          // sum k
    long double S2 = (r - 1.0L) * r * (2.0L * r - 1.0L) / 6.0L;      // sum k^2
    long double S3 = S1 * S1;                                        // sum k^3
    long double ST = 2.0L * S3 - 3.0L * S2 + S1;                     // sum(2k^3-3k^2+k)

    rep(j, N) {
      int p0i = s.P[0][j];
      if (p0i == 0) continue;

      long double b0 = (long double)s.B[0][j];
      long double b1 = (long double)s.B[1][j];
      long double b2 = (long double)s.B[2][j];
      long double b3 = (long double)s.B[3][j];

      long double p1 = (long double)s.P[1][j];
      long double p2 = (long double)s.P[2][j];
      long double p3 = (long double)s.P[3][j];

      long double d2 = b3 * p3;

      long double c0 = b1;
      long double c2 = (p2 * d2) / 2.0L;
      long double c1 = p2 * b2 - c2;

      long double sum_prefix =
        c0 * S1 +
        (c1 / 2.0L) * (S2 - S1) +
        (c2 / 6.0L) * ST;

      long double sum_b0 = b0 * r + p1 * sum_prefix;

      long double gain = (long double)A[j] * (long double)p0i * sum_b0;
      res += gain;
    }

    clampApple(res);
    return res;
  }

  inline long double evaluate(const State &s, int remaining_turns) const {
    return project_no_more_upgrades(s, remaining_turns);
  }

  inline bool can_upgrade(const State &s, int i, int j, long double &cost_out) const {
    long double cost = (long double)C[i][j] * (long double)(s.P[i][j] + 1);
    cost_out = cost;
    return s.apples + 1e-18L >= cost;
  }

  inline long double heuristic_gain(const State &s, int i, int j, int turns_including_this) const {
    long double R = (long double)turns_including_this;
    if (R <= 0) return 0;

    long double a = (long double)A[j];
    long double b0 = (long double)s.B[0][j];
    long double b1 = (long double)s.B[1][j];
    long double b2 = (long double)s.B[2][j];
    long double b3 = (long double)s.B[3][j];

    long double p0 = (long double)max(1, s.P[0][j]);
    long double p1 = (long double)max(1, s.P[1][j]);
    long double p2 = (long double)max(1, s.P[2][j]);

    long double comb1 = R;
    long double comb2 = R * (R - 1.0L) / 2.0L;
    long double comb3 = R * (R - 1.0L) * (R - 2.0L) / 6.0L;
    long double comb4 = R * (R - 1.0L) * (R - 2.0L) * (R - 3.0L) / 24.0L;

    if (i == 0) return a * b0 * comb1;
    if (i == 1) return a * p0 * b1 * comb2;
    if (i == 2) return a * p0 * p1 * b2 * comb3;
    return a * p0 * p1 * p2 * b3 * comb4;
  }

  // 時間切れ近いときに確実にT手埋める（1本貪欲）
  int greedy_finish(State s, int t_start, double deadlineMs) {
    for (int t = t_start; t < T; t++) {
      if (utility::mytm.elapsedMs() > deadlineMs - 5.0) break;

      int remaining = T - 1 - t;

      int best_i = -1, best_j = -1;
      long double best_score;

      // 何もしない
      State best = s;
      traces.emplace_back(-1, -1, s.trace_id);
      best.trace_id = (int)traces.size() - 1;
      process_production(best);
      best.score = evaluate(best, remaining);
      best_score = best.score;

      // 強化
      rep(i, L) rep(j, N) {
        long double cost;
        if (!can_upgrade(s, i, j, cost)) continue;

        State ns = s;
        ns.apples -= cost;
        ns.P[i][j]++;

        traces.emplace_back(i, j, s.trace_id);
        ns.trace_id = (int)traces.size() - 1;

        process_production(ns);
        ns.score = evaluate(ns, remaining);

        if (ns.score > best_score) {
          best_score = ns.score;
          best = ns;
          best_i = i;
          best_j = j;
        }
      }

      s = best;
    }
    return s.trace_id;
  }

  // 1回のビーム探索（ランダム揺らぎあり）
  pair<long double, vector<pair<int,int>>> runOne(const Params &p, mt19937_64 &rng, double deadlineMs) {
    traces.clear();
    traces.reserve(p.traceReserve);

    uniform_real_distribution<double> uni01(0.0, 1.0);

    auto randNoise = [&](double amp) -> double {
      // [-amp, +amp] の一様ノイズ
      return (uni01(rng) * 2.0 - 1.0) * amp;
    };

    State init;
    init.apples = (long double)K;
    init.score = evaluate(init, T);

    vector<State> beam;
    beam.reserve(p.bwEarly);
    beam.push_back(init);

    int last_trace_id = -1;

    auto keep_top_k = [&](vector<State> &v, int k) {
      if ((int)v.size() <= k) {
        sort(v.begin(), v.end(), [](const State &a, const State &b) { return a.score > b.score; });
        return;
      }
      nth_element(v.begin(), v.begin() + k, v.end(),
        [](const State &a, const State &b) { return a.score > b.score; });
      v.resize(k);
      sort(v.begin(), v.end(), [](const State &a, const State &b) { return a.score > b.score; });
    };

    for (int t = 0; t < T; t++) {
      if (utility::mytm.elapsedMs() > deadlineMs - p.safetyMs) {
        int best_idx = 0;
        rep(i, (int)beam.size()) if (beam[i].score > beam[best_idx].score) best_idx = i;
        last_trace_id = greedy_finish(beam[best_idx], t, deadlineMs);
        goto DONE;
      }

      int remaining = T - 1 - t;

      int BW;
      if (t < 120) BW = p.bwEarly;
      else if (t < 260) BW = p.bwMid;
      else if (t < 420) BW = p.bwLate;
      else BW = p.bwEnd;

      int guarantee = (t < 240 ? p.guaranteeEarly : p.guaranteeLate);

      vector<vector<State>> buckets(N + 1);
      rep(b, N + 1) buckets[b].reserve((int)beam.size());

      for (const auto &cur : beam) {
        // 何もしない
        {
          State ns = cur;
          traces.emplace_back(-1, -1, cur.trace_id);
          ns.trace_id = (int)traces.size() - 1;
          process_production(ns);
          ns.score = evaluate(ns, remaining) * (1.0L + (long double)randNoise(1e-6)); // 微小揺らぎ
          buckets[N].push_back(ns);
        }

        struct Cand {
          int i, j;
          long double cost;
          long double ratio;
          long double gain;
        };
        vector<Cand> cand;
        cand.reserve(40);

        int turns_including_this = remaining + 1;

        rep(i, L) rep(j, N) {
          long double cost;
          if (!can_upgrade(cur, i, j, cost)) continue;

          long double g = heuristic_gain(cur, i, j, turns_including_this);

          // 早い段階は上位レベルをほんの少し優遇（立ち上げ用）
          long double level_bonus = 1.0L + (long double)(i) * (t < 220 ? 0.05L : 0.02L);
          g *= level_bonus;

          long double ratio = g / (cost + 1e-18L);

          // ランダム揺らぎで多様性を確保
          ratio *= (1.0L + (long double)randNoise(p.noiseRatio));
          g     *= (1.0L + (long double)randNoise(p.noiseGain));

          cand.push_back({i, j, cost, ratio, g});
        }

        if (cand.empty()) continue;

        // ratio上位 kr
        vector<int> sel;
        sel.reserve(p.kr + p.kg + p.randomExtra);

        {
          int take = min(p.kr, (int)cand.size());
          nth_element(cand.begin(), cand.begin() + take - 1, cand.end(),
            [](const Cand &a, const Cand &b) { return a.ratio > b.ratio; });
          vector<Cand> top;
          top.reserve(take);
          rep(k, take) top.push_back(cand[k]);
          sort(top.begin(), top.end(), [](const Cand &a, const Cand &b) { return a.ratio > b.ratio; });

          bool used[4][10];
          rep(ii, 4) rep(jj, 10) used[ii][jj] = false;

          for (auto &x : top) {
            if (used[x.i][x.j]) continue;
            used[x.i][x.j] = true;
            sel.push_back(x.i * 10 + x.j);
          }

          // gain上位 kg
          int take2 = min(p.kg, (int)cand.size());
          nth_element(cand.begin(), cand.begin() + take2 - 1, cand.end(),
            [](const Cand &a, const Cand &b) { return a.gain > b.gain; });
          vector<Cand> top2;
          top2.reserve(take2);
          rep(k, take2) top2.push_back(cand[k]);
          sort(top2.begin(), top2.end(), [](const Cand &a, const Cand &b) { return a.gain > b.gain; });

          for (auto &x : top2) {
            if (used[x.i][x.j]) continue;
            used[x.i][x.j] = true;
            sel.push_back(x.i * 10 + x.j);
          }

          // ランダム追加
          if (p.randomExtra > 0 && (int)sel.size() < (int)cand.size()) {
            // 候補をシャッフルして、未使用を少しだけ追加
            vector<int> order((int)cand.size());
            rep(k, (int)cand.size()) order[k] = k;
            shuffle(order.begin(), order.end(), rng);

            int added = 0;
            for (int idx : order) {
              int key = cand[idx].i * 10 + cand[idx].j;
              bool ok = true;
              for (int v : sel) if (v == key) { ok = false; break; }
              if (!ok) continue;
              sel.push_back(key);
              added++;
              if (added >= p.randomExtra) break;
            }
          }
        }

        // 展開
        for (int key : sel) {
          int i = key / 10;
          int j = key % 10;

          long double cost = (long double)C[i][j] * (long double)(cur.P[i][j] + 1);
          if (cur.apples + 1e-18L < cost) continue;

          State ns = cur;
          ns.apples -= cost;
          ns.P[i][j]++;

          traces.emplace_back(i, j, cur.trace_id);
          ns.trace_id = (int)traces.size() - 1;

          process_production(ns);
          ns.score = evaluate(ns, remaining) * (1.0L + (long double)randNoise(2e-6));
          buckets[j].push_back(ns);
        }
      }

      vector<State> next_beam;
      next_beam.reserve(BW);

      vector<State> pool;
      pool.reserve(BW * 4);

      for (int b = 0; b <= N; b++) {
        auto &v = buckets[b];
        if (v.empty()) continue;

        // まず上位を取りたいので少し多めに残す
        int cap = min((int)v.size(), max(guarantee, 40));
        keep_top_k(v, cap);

        int take = min(guarantee, (int)v.size());
        rep(k, take) next_beam.push_back(v[k]);

        for (int k = take; k < (int)v.size() && (int)pool.size() < BW * 4; k++) {
          pool.push_back(v[k]);
        }
      }

      if ((int)next_beam.size() < BW && !pool.empty()) {
        int need = BW - (int)next_beam.size();
        keep_top_k(pool, min(need, (int)pool.size()));
        rep(i, min(need, (int)pool.size())) next_beam.push_back(pool[i]);
      }

      if (next_beam.empty()) {
        // 念のため
        State s;
        s.apples = (long double)K;
        last_trace_id = greedy_finish(s, t, deadlineMs);
        goto DONE;
      }

      sort(next_beam.begin(), next_beam.end(),
        [](const State &a, const State &b) { return a.score > b.score; });
      if ((int)next_beam.size() > BW) next_beam.resize(BW);
      beam.swap(next_beam);
    }

    {
      // 最終りんご最大
      int best_idx = 0;
      rep(i, (int)beam.size()) if (beam[i].apples > beam[best_idx].apples) best_idx = i;
      last_trace_id = beam[best_idx].trace_id;
    }

  DONE:
    vector<pair<int,int>> moves;
    moves.reserve(T);

    int cur = last_trace_id;
    while (cur != -1) {
      moves.push_back({traces[cur].i, traces[cur].j});
      cur = traces[cur].parent_id;
    }
    reverse(moves.begin(), moves.end());
    while ((int)moves.size() < T) moves.push_back({-1, -1});
    if ((int)moves.size() > T) moves.resize(T);

    // 最終りんごを計算し直すのは重いので、ここではscore/beamのapples比較ではなく、
    // run中に選んだ状態由来の apples を戻せないため、概算として最後のtraceから復元はしない。
    // 代わりに「この run の best を評価値(score)最大」で取る設計にしているので score を返す。
    // ただし score は最終りんご予測なので、比較用には十分強い。
    long double bestProjected = -1;
    // scoreはビームの先頭が最大に近いが、t切り替えがあるので movesだけ返し、比較は呼び出し元で行う。
    // ここでは bestProjected として、最後のビームの先頭score相当を返すのが理想だが、DONEに来る経路で不明。
    // よって比較は呼び出し元で「movesを適用して最終りんご」をシミュレートする。
    (void)bestProjected;

    return {0.0L, moves}; // applesは呼び出し元で再シミュレート
  }

  // moves を適用して最終りんごを正確に計算
  long double simulateFinal(const vector<pair<int,int>> &moves) const {
    State s;
    s.apples = (long double)K;

    for (int t = 0; t < T; t++) {
      int i = moves[t].first;
      int j = moves[t].second;
      if (i != -1) {
        long double cost = (long double)C[i][j] * (long double)(s.P[i][j] + 1);
        if (s.apples + 1e-18L >= cost) { // 念のため
          s.apples -= cost;
          s.P[i][j]++;
        }
      }
      process_production(s);
    }
    return s.apples;
  }

  void solve() {
    utility::mytm.CodeStart();

    // ここを「2000 sec に収まりそう」に合わせる（ミリ秒）
    const double TIME_LIMIT_MS = 2000.0 * 1.0;

    Params base;

    // 反復ビーム（ランダム揺らぎ付き）で時間を使い切る
    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<pair<int,int>> bestMoves;
    long double bestApples = -1;

    // まだ時間があるなら、少しずつパラメータを揺らして探索
    int iter = 0;
    while (utility::mytm.elapsedMs() < TIME_LIMIT_MS - 600.0) {
      Params p = base;

      // 残り時間が多いときほど重くする
      double left = TIME_LIMIT_MS - utility::mytm.elapsedMs();
      if (left > 900.0 * 1000.0) {
        p.bwEarly = 1200;
        p.bwMid   = 800;
        p.bwLate  = 520;
        p.bwEnd   = 260;
        p.kr = 14; p.kg = 8; p.randomExtra = 6;
      } else if (left > 300.0 * 1000.0) {
        p.bwEarly = 1000;
        p.bwMid   = 650;
        p.bwLate  = 420;
        p.bwEnd   = 220;
        p.kr = 13; p.kg = 7; p.randomExtra = 5;
      } else {
        p.bwEarly = 850;
        p.bwMid   = 550;
        p.bwLate  = 350;
        p.bwEnd   = 180;
        p.kr = 12; p.kg = 6; p.randomExtra = 3;
      }

      // 反復ごとにノイズを微調整（探索の多様性）
      p.noiseRatio = base.noiseRatio * (1.0 + 0.10 * (iter % 5));
      p.noiseGain  = base.noiseGain  * (1.0 + 0.10 * ((iter + 2) % 5));

      // 1回の探索を実行
      auto [dummy, moves] = runOne(p, rng, TIME_LIMIT_MS);

      long double finalApples = simulateFinal(moves);
      if (finalApples > bestApples) {
        bestApples = finalApples;
        bestMoves = moves;
      }

      iter++;
    }

    // 万一 bestMoves が空なら保険で全部 -1
    if (bestMoves.empty()) {
      bestMoves.assign(T, {-1, -1});
    }

    rep(t, T) {
      int i = bestMoves[t].first;
      int j = bestMoves[t].second;
      if (i == -1) cout << -1 << "\n";
      else cout << i << " " << j << "\n";
    }
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  Solver solver;
  solver.solve();
  return 0;
}
