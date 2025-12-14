/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc058/submissions/71727352
 * Submitted at: 2025-12-14 18:59:59
 * Problem URL: https://atcoder.jp/contests/ahc058/tasks/ahc058_a
 * Result: AC
 * Execution Time: 1992 ms
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
    double elapsed() const {
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

// ---------------------------------------------------------

struct State {
  int trace_id;
  long double apples;
  double B[4][10];
  int P[4][10];
  long double score;

  // comparator用：固定のタイブレーク（sort中に変化しない）
  uint64_t tie;

  State() : trace_id(-1), apples(0), score(0), tie(0) {
    rep(i, 4) rep(j, 10) {
      B[i][j] = 1.0;
      P[i][j] = 0;
    }
  }
};

// splitmix64 (fast RNG)
struct SplitMix64 {
  uint64_t x;
  explicit SplitMix64(uint64_t seed = 0) : x(seed) {}
  uint64_t next_u64() {
    uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
  }
  double next_double() { // [0,1)
    return (next_u64() >> 11) * (1.0 / 9007199254740992.0);
  }
};

struct Params {
  int BW_EARLY = 700;
  int BW_MID   = 450;
  int BW_LATE  = 280;
  int BW_END   = 140;

  int guarantee_early = 2;
  int guarantee_late  = 1;

  int KR = 7;
  int KG = 4;
};

struct RunResult {
  long double final_apples = -1;
  vector<pair<int,int>> moves; // size T
};

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() {
  return (double) (rand_int() % (int) 1e9) / 1e9;
}

struct Solver {
  int N, L, T;
  long long K;
  vector<int> A;
  vector<vector<long long>> C;

  static constexpr long double APPLE_CAP = 1e300L;
  static constexpr double B_CAP = 1e200;

  Solver() { input(); }

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

  // 「これ以上強化しない」前提での最終りんご（固定Pの閉形式）
  inline long double project_no_more_upgrades(const State &s, int R) const {
    if (R <= 0) return s.apples;

    long double res = s.apples;
    long double r = (long double)R;

    long double S1 = r * (r - 1.0L) / 2.0L;
    long double S2 = (r - 1.0L) * r * (2.0L * r - 1.0L) / 6.0L;
    long double S3 = S1 * S1;
    long double ST = 2.0L * S3 - 3.0L * S2 + S1;

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
    // 残りターン数が大きいほどより乱数を入れる
    res += ((r + rand_int() % 15) / T) * res;
    return res;
  }

  inline long double evaluate_after_production(const State &s_after, int remaining_turns) const {
    return project_no_more_upgrades(s_after, remaining_turns);
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

  static inline bool better_state(const State &a, const State &b) {
    if (a.score != b.score) return a.score > b.score;
    return a.tie > b.tie;
  }

  int greedy_finish(State s, int t_start, vector<Trace> &traces, const Params &pm) const {
    for (int t = t_start; t < T; t++) {
      int remaining = T - 1 - t;

      int best_i = -1, best_j = -1;
      State best_ns;
      long double best_score = -1;

      // wait
      {
        State ns = s;
        process_production(ns);
        ns.score = evaluate_after_production(ns, remaining);
        best_score = ns.score;
        best_ns = ns;
        best_i = -1; best_j = -1;
      }

      // upgrades full scan
      rep(i, L) rep(j, N) {
        long double cost;
        if (!can_upgrade(s, i, j, cost)) continue;
        State ns = s;
        ns.apples -= cost;
        ns.P[i][j]++;

        process_production(ns);
        ns.score = evaluate_after_production(ns, remaining);

        if (ns.score > best_score) {
          best_score = ns.score;
          best_ns = ns;
          best_i = i;
          best_j = j;
        }
      }

      traces.emplace_back(best_i, best_j, s.trace_id);
      best_ns.trace_id = (int)traces.size() - 1;
      s = best_ns;
    }
    return s.trace_id;
  }

  RunResult run_once(const Params &pm, uint64_t seed, double global_deadline_ms) const {
    SplitMix64 rng(seed);

    vector<Trace> traces;
    // 目安：earlyで 700*(1+KR+KG+1) ≈ 700*13=9100/turn, 500turn で 4.5M 程度
    traces.reserve(8000000);

    State init;
    init.apples = (long double)K;
    init.trace_id = -1;
    init.tie = rng.next_u64();

    vector<State> beam;
    beam.reserve(pm.BW_EARLY);
    beam.push_back(init);

    int last_trace_id = -1;

    auto assign_tie = [&](State &s) { s.tie = rng.next_u64(); };

    for (int t = 0; t < T; t++) {
      if (utility::mytm.elapsed() > global_deadline_ms) {
        int best_idx = 0;
        rep(i, (int)beam.size()) if (beam[i].apples > beam[best_idx].apples) best_idx = i;
        last_trace_id = greedy_finish(beam[best_idx], t, traces, pm);
        goto RECONSTRUCT;
      }

      int remaining = T - 1 - t;

      int BW;
      if (t < 120) BW = pm.BW_EARLY;
      else if (t < 260) BW = pm.BW_MID;
      else if (t < 420) BW = pm.BW_LATE;
      else BW = pm.BW_END;

      int guarantee = (t < 220 ? pm.guarantee_early : pm.guarantee_late);

      vector<vector<State>> buckets(N + 1);
      rep(b, N + 1) buckets[b].reserve((int)beam.size());

      for (const auto &cur : beam) {
        // wait child
        {
          State ns = cur;
          traces.emplace_back(-1, -1, cur.trace_id);
          ns.trace_id = (int)traces.size() - 1;
          assign_tie(ns);

          process_production(ns);
          ns.score = evaluate_after_production(ns, remaining);
          buckets[N].push_back(ns);
        }

        // base projection for delta
        long double base_proj = project_no_more_upgrades(cur, remaining + 1);

        // cheap prefilter: per j take best ratio and best gain (max 2*N)
        bool picked[4][10];
        rep(i, 4) rep(j, 10) picked[i][j] = false;

        vector<pair<int,int>> pre;
        pre.reserve(2 * N);

        int turns_including_this = remaining + 1;

        rep(j, N) {
          long double best_r = -1;
          int best_ri = -1;
          long double best_g = -1;
          int best_gi = -1;

          rep(i, L) {
            long double cost;
            if (!can_upgrade(cur, i, j, cost)) continue;
            long double g = heuristic_gain(cur, i, j, turns_including_this);
            long double r = g / (cost + 1e-18L);

            long double level_bonus = 1.0L + (long double)(3 - i) * (t < 250 ? 0.05L : 0.02L);
            r *= level_bonus;
            g *= level_bonus;

            if (r > best_r) { best_r = r; best_ri = i; }
            if (g > best_g) { best_g = g; best_gi = i; }
          }

          if (best_ri != -1) {
            picked[best_ri][j] = true;
            pre.push_back({best_ri, j});
          }
          if (best_gi != -1 && !picked[best_gi][j]) {
            picked[best_gi][j] = true;
            pre.push_back({best_gi, j});
          }
        }

        if (!pre.empty()) {
          struct Cand2 {
            int i, j;
            long double delta;
            long double ratio;
          };
          vector<Cand2> cand2;
          cand2.reserve(pre.size());

          for (auto [i, j] : pre) {
            long double cost = (long double)C[i][j] * (long double)(cur.P[i][j] + 1);
            if (cur.apples + 1e-18L < cost) continue;

            State tmp = cur;
            tmp.apples -= cost;
            tmp.P[i][j]++;

            long double proj = project_no_more_upgrades(tmp, remaining + 1);
            long double delta = proj - base_proj;
            if (delta <= 0) continue;

            long double ratio = delta / (cost + 1e-18L);
            cand2.push_back({i, j, delta, ratio});
          }

          if (!cand2.empty()) {
            vector<pair<int,int>> selected;
            selected.reserve(pm.KR + pm.KG + 2);

            bool used2[4][10];
            rep(i, 4) rep(j, 10) used2[i][j] = false;

            auto take_top = [&](int k, auto cmp) {
              k = min(k, (int)cand2.size());
              if (k <= 0) return;
              nth_element(cand2.begin(), cand2.begin() + (k - 1), cand2.end(), cmp);
              vector<Cand2> top;
              top.reserve(k);
              rep(tk, k) top.push_back(cand2[tk]);
              sort(top.begin(), top.end(), cmp);
              for (auto &x : top) {
                if (!used2[x.i][x.j]) {
                  used2[x.i][x.j] = true;
                  selected.push_back({x.i, x.j});
                }
              }
            };

            take_top(pm.KR, [&](const Cand2 &a, const Cand2 &b){
              if (a.ratio != b.ratio) return a.ratio > b.ratio;
              return a.delta > b.delta;
            });
            take_top(pm.KG, [&](const Cand2 &a, const Cand2 &b){
              if (a.delta != b.delta) return a.delta > b.delta;
              return a.ratio > b.ratio;
            });

            for (auto [i, j] : selected) {
              long double cost = (long double)C[i][j] * (long double)(cur.P[i][j] + 1);
              if (cur.apples + 1e-18L < cost) continue;

              State ns = cur;
              ns.apples -= cost;
              ns.P[i][j]++;

              traces.emplace_back(i, j, cur.trace_id);
              ns.trace_id = (int)traces.size() - 1;
              assign_tie(ns);

              process_production(ns);
              ns.score = evaluate_after_production(ns, remaining);
              buckets[j].push_back(ns);
            }
          }
        }
      }

      // 次ビーム選択：各バケットから保証枠 + 残りを全体上位
      vector<State> next_beam;
      next_beam.reserve(BW);

      vector<State> pool;
      pool.reserve(BW * 3);

      auto keep_top_k = [&](vector<State> &v, int k) {
        if ((int)v.size() <= k) {
          sort(v.begin(), v.end(), better_state);
          return;
        }
        nth_element(v.begin(), v.begin() + k, v.end(), [&](const State &a, const State &b){
          if (a.score != b.score) return a.score > b.score;
          return a.tie > b.tie;
        });
        v.resize(k);
        sort(v.begin(), v.end(), better_state);
      };

      for (int b = 0; b <= N; b++) {
        auto &v = buckets[b];
        if (v.empty()) continue;

        int take = min(guarantee, (int)v.size());
        keep_top_k(v, min((int)v.size(), take + 24)); // 少しだけ余りを残して pool に流す

        rep(k, take) next_beam.push_back(v[k]);

        for (int k = take; k < (int)v.size() && (int)pool.size() < BW * 3; k++) {
          pool.push_back(v[k]);
        }
      }

      if ((int)next_beam.size() < BW && !pool.empty()) {
        int need = BW - (int)next_beam.size();
        keep_top_k(pool, min(need, (int)pool.size()));
        rep(i, min(need, (int)pool.size())) next_beam.push_back(pool[i]);
      }

      sort(next_beam.begin(), next_beam.end(), better_state);
      if ((int)next_beam.size() > BW) next_beam.resize(BW);
      beam.swap(next_beam);

      if (beam.empty()) {
        State s;
        s.apples = (long double)K;
        last_trace_id = greedy_finish(s, t, traces, pm);
        goto RECONSTRUCT;
      }
    }

    // 通常終了：最終りんご最大
    {
      int best_idx = 0;
      rep(i, (int)beam.size()) if (beam[i].apples > beam[best_idx].apples) best_idx = i;
      last_trace_id = beam[best_idx].trace_id;
    }

  RECONSTRUCT:
    RunResult rr;
    rr.moves.reserve(T);

    vector<pair<int,int>> moves;
    moves.reserve(T);

    int cur_id = last_trace_id;
    while (cur_id != -1) {
      moves.push_back({traces[cur_id].i, traces[cur_id].j});
      cur_id = traces[cur_id].parent_id;
    }
    reverse(moves.begin(), moves.end());
    while ((int)moves.size() < T) moves.push_back({-1, -1});
    if ((int)moves.size() > T) moves.resize(T);

    // final apples を堅実に算出（T=500なので軽い）
    {
      State s;
      s.apples = (long double)K;
      rep(i, 4) rep(j, 10) { s.B[i][j] = 1.0; s.P[i][j] = 0; }

      rep(t, T) {
        int ai = moves[t].first;
        int aj = moves[t].second;
        if (ai != -1) {
          long double cost = (long double)C[ai][aj] * (long double)(s.P[ai][aj] + 1);
          if (s.apples + 1e-18L >= cost) {
            s.apples -= cost;
            s.P[ai][aj]++;
          }
        }
        process_production(s);
      }
      rr.final_apples = s.apples;
    }

    rr.moves = std::move(moves);
    return rr;
  }

  void solve() {
    utility::mytm.CodeStart();
    const double TIME_LIMIT_MS = 2000.0;

    Params base;

    RunResult best;
    best.final_apples = -1;

    uint64_t base_seed = 0x123456789abcdef0ULL;
    base_seed ^= (uint64_t)K * 0x9e3779b97f4a7c15ULL;

    int iter = 0;
    while (true) {
      double now = utility::mytm.elapsed();
      if (now > TIME_LIMIT_MS - 35.0) break;

      Params pm = base;

      if (iter % 4 == 0) { pm.KR = 1; pm.KG = 1; }
      if (iter % 4 == 1) { pm.KR = 1; pm.KG = 2; }
      if (iter % 4 == 2) { pm.KR = 2; pm.KG = 1; }
      if (iter % 4 == 3) { pm.KR = 2; pm.KG = 2; }

      pm.guarantee_early = 2;
      pm.guarantee_late  = 1;

      uint64_t seed = base_seed ^ (uint64_t)(iter + 1) * 0x9e3779b97f4a7c15ULL;

      double deadline = TIME_LIMIT_MS - 12.0;
      RunResult rr = run_once(pm, seed, deadline);

      if (rr.final_apples > best.final_apples) {
        best = std::move(rr);
      }

      iter++;
      cerr << "iter " << iter << ", best apples = " << (long long)(best.final_apples) << ", time = " << now << " ms\n";
    }

    if (best.final_apples < 0) {
      rep(t, T) cout << -1 << "\n";
      return;
    }

    rep(t, T) {
      int i = best.moves[t].first;
      int j = best.moves[t].second;
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
