/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc050/submissions/67389939
 * Submitted at: 2025-07-06 22:03:41
 * Problem URL: https://atcoder.jp/contests/ahc050/tasks/ahc050_a
 * Result: AC
 * Execution Time: 1914 ms
 */

#include <bits/stdc++.h>
using namespace std;

/* ---------- 共通定義 ---------- */
constexpr int N = 40;

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty; ty = tz; tz = tw;
  return tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8));
}

namespace utility {
  struct timer {
    chrono::system_clock::time_point start;
    void CodeStart() { start = chrono::system_clock::now(); }
    double elapsed() const {
      return static_cast<double>(chrono::duration_cast<chrono::milliseconds>(
                                     chrono::system_clock::now() - start)
                                     .count());
    }
  } mytm;
}

/* ────────────────── Runner ────────────────── */
class Runner {
public:
  Runner(const vector<string>& s, const vector<pair<int, int>>& ec)
      : S(s), empty_cells(ec) {}

  pair<double, vector<pair<int, int>>> run(int random_pool_size);

private:
  /* 入力情報 */
  const vector<string>& S;
  const vector<pair<int, int>>& empty_cells;

  /* 盤面状態 */
  bool is_rock[N][N]{};

  /* 移動停止位置キャッシュ */
  int up_stop[N][N], down_stop[N][N], left_stop[N][N], right_stop[N][N];

  /* 確率 DP 用バッファ (二枚分) */
  double prob1[N][N]{}, prob2[N][N]{};

  /* 内部 util */
  void compute_all_stops();
  void update_stops(int r, int c);

  /* 速度用ワーク */
  vector<int> unplaced_idx;  // empty_cells へのインデックスを保持
};

/* ────────────────── Solver ────────────────── */
struct Solver {
  int M;
  vector<string> S;
  vector<pair<int, int>> empty_cells;

  Solver() {
    int n_dummy;
    cin >> n_dummy >> M;
    S.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> S[i];
      for (int j = 0; j < N; ++j)
        if (S[i][j] == '.') empty_cells.emplace_back(i, j);
    }
  }

  void solve() {
    utility::mytm.CodeStart();

    Runner runner(S, empty_cells);
    double best_E = -1.0;
    vector<pair<int, int>> best_P;
    long long iter = 0;

    while (utility::mytm.elapsed() < 1900) {
      int pool = 1 + (rand_int() % 10);
      auto [E, P] = runner.run(pool);
      if (E > best_E) {
        best_E = E;
        best_P = move(P);
      }
      ++iter;
    }
    cerr << "Total Iterations: " << iter << '\n';
    for (auto [r, c] : best_P) cout << r << ' ' << c << '\n';
  }
};

/* ────────────────── Main ────────────────── */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
  Solver().solve();
  return 0;
}

/* ────────────────── Runner 実装 ────────────────── */
pair<double, vector<pair<int, int>>> Runner::run(int random_pool_size) {
  /* 初期化 ------------------------------------------------------------ */
  vector<pair<int, int>> placed;
  placed.reserve(empty_cells.size());

  /* 壁配置と確率配列初期化 */
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
      is_rock[i][j] = (S[i][j] == '#');
      prob1[i][j] = prob2[i][j] = 0.0;
    }
  if (!empty_cells.empty()) {
    double p0 = 1.0 / empty_cells.size();
    for (auto [r, c] : empty_cells) prob1[r][c] = p0;
  }
  compute_all_stops();

  /* 未配置セル index 初期化 (pop+swap で O(1) 削除) */
  unplaced_idx.clear();
  unplaced_idx.reserve(empty_cells.size());
  for (int i = 0; i < (int)empty_cells.size(); ++i) unplaced_idx.push_back(i);

  double expected_prize = 0.0, prob_alive = 1.0;
  double(*cur)[N] = prob1;
  double(*nxt)[N] = prob2;

  /* シミュレーション -------------------------------------------------- */
  for (int step = 0; step < (int)empty_cells.size(); ++step) {
    /* 移動遷移 */
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) nxt[i][j] = 0.0;

    double total_prob_before_move = 0.0;
    for (int r = 0; r < N; ++r)
      for (int c = 0; c < N; ++c)
        if (cur[r][c] > 1e-12) {
          total_prob_before_move += cur[r][c];
          double p4 = cur[r][c] * 0.25;
          nxt[up_stop[r][c]][c] += p4;
          nxt[down_stop[r][c]][c] += p4;
          nxt[r][left_stop[r][c]] += p4;
          nxt[r][right_stop[r][c]] += p4;
        }
    swap(cur, nxt);

    /* 候補探索 (1 pass) */
    double min_p = 2.0;
    for (int idx : unplaced_idx) {
      auto [r, c] = empty_cells[idx];
      min_p = min(min_p, cur[r][c]);
    }

    vector<int> cand_idx;
    cand_idx.reserve(unplaced_idx.size());
    for (int idx : unplaced_idx) {
      auto [r, c] = empty_cells[idx];
      if (fabs(cur[r][c] - min_p) < 1e-12) cand_idx.push_back(idx);
    }

    int best_idx;
    if (cand_idx.size() <= 1) {
      best_idx = cand_idx.empty() ? unplaced_idx.back() : cand_idx.front();
    } else {
      struct Scored {
        double score;
        int idx;
      };
      vector<Scored> scored;
      scored.reserve(cand_idx.size());
      for (int idx : cand_idx) {
        auto [r, c] = empty_cells[idx];
        int up_len = r - up_stop[r][c];
        int down_len = down_stop[r][c] - r;
        int left_len = c - left_stop[r][c];
        int right_len = right_stop[r][c] - c;
        double pen = static_cast<double>(up_len * down_len) +
                     static_cast<double>(left_len * right_len);
        scored.push_back({pen, idx});
      }

      int pool = min<int>(scored.size(), random_pool_size);
      nth_element(scored.begin(), scored.begin() + pool, scored.end(),
                  [](const Scored& a, const Scored& b) {
                    return a.score < b.score;
                  });
      best_idx = scored[rand_int() % pool].idx;
    }

    /* 選択セル確定 */
    auto [br, bc] = empty_cells[best_idx];
    placed.push_back({br, bc});

    /* 未配置リストから削除 (swap pop) */
    auto it = find(unplaced_idx.begin(), unplaced_idx.end(), best_idx);
    swap(*it, unplaced_idx.back());
    unplaced_idx.pop_back();

    /* 確率更新 */
    double destroyed_prob = cur[br][bc];
    cur[br][bc] = 0.0;
    double remain_sum = total_prob_before_move - destroyed_prob;
    if (total_prob_before_move > 1e-12)
      prob_alive *= remain_sum / total_prob_before_move;
    expected_prize += prob_alive;

    if (remain_sum > 1e-12) {
      double inv = 1.0 / remain_sum;
      for (int r = 0; r < N; ++r)
        for (int c = 0; c < N; ++c) cur[r][c] *= inv;
    }

    /* 盤面更新 */
    is_rock[br][bc] = true;
    update_stops(br, bc);
  }
  return {expected_prize, move(placed)};
}

/* ---- 移動停止位置テーブル全再計算 ---- */
void Runner::compute_all_stops() {
  for (int i = 0; i < N; ++i) {
    int last = -1;
    for (int j = 0; j < N; ++j) {
      left_stop[i][j] = last + 1;
      if (is_rock[i][j]) last = j;
    }
    last = N;
    for (int j = N - 1; j >= 0; --j) {
      right_stop[i][j] = last - 1;
      if (is_rock[i][j]) last = j;
    }
  }
  for (int j = 0; j < N; ++j) {
    int last = -1;
    for (int i = 0; i < N; ++i) {
      up_stop[i][j] = last + 1;
      if (is_rock[i][j]) last = i;
    }
    last = N;
    for (int i = N - 1; i >= 0; --i) {
      down_stop[i][j] = last - 1;
      if (is_rock[i][j]) last = i;
    }
  }
}

/* ---- 1 マス岩追加時の停止位置差分更新 ---- */
void Runner::update_stops(int r, int c) {
  /* 上下方向 */
  int pr = -1;
  for (int i = r - 1; i >= 0; --i)
    if (is_rock[i][c]) {
      pr = i;
      break;
    }
  for (int i = r - 1; i > pr; --i) down_stop[i][c] = r - 1;

  int nr = N;
  for (int i = r + 1; i < N; ++i)
    if (is_rock[i][c]) {
      nr = i;
      break;
    }
  for (int i = r + 1; i < nr; ++i) up_stop[i][c] = r + 1;

  /* 左右方向 */
  int pc = -1;
  for (int j = c - 1; j >= 0; --j)
    if (is_rock[r][j]) {
      pc = j;
      break;
    }
  for (int j = c - 1; j > pc; --j) right_stop[r][j] = c - 1;

  int nc = N;
  for (int j = c + 1; j < N; ++j)
    if (is_rock[r][j]) {
      nc = j;
      break;
    }
  for (int j = c + 1; j < nc; ++j) left_stop[r][j] = c + 1;
}
