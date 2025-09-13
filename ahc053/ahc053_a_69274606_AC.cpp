/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69274606
 * Submitted at: 2025-09-13 19:44:11
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;

struct Node { long long d; int j; };
struct Cmp {
  bool operator()(const Node& a, const Node& b) const {
    if (a.d != b.d) return a.d < b.d; // max-heap
    return a.j > b.j;
  }
};

static inline unsigned long long pow2_ull(int e){
  if (e >= 63) return (1ULL << 62); // guard
  return (1ULL << e);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  long long L, U;
  if (!(cin >> N >> M >> L >> U)) return 0;

  // ---- 1) 設計（L + 残差ビット + 微調整） ----
  unsigned long long W = (U >= L) ? (unsigned long long)(U - L) : 0ULL;

  // 各山に L を 1 枚（M 枚）
  int fixed_L = min(M, N);
  int free_all  = max(0, N - fixed_L);

  // 微調整コインは 2 枚/山 分確保（R_fine=2M）。カードが足りなければ縮小。
  int R_fine = min(free_all, 2 * M);
  int free_for_bits = free_all - R_fine;

  // 各ビット段で必要な在庫：M/2 + z*sqrt(M)/2（需要の 3σ 余裕）
  double z = 3.0;
  int C_need = (int)ceil(0.5 * M + 0.5 * z * sqrt((double)M));
  C_need = min(C_need, M); // 1 段で山 1 つにつき 1 枚しか使えない

  // 取れる段数 K を最大化（桁あふれ防止に 60 で上限）
  int K = 0;
  if (W > 0 && free_for_bits > 0) {
    K = min(60, free_for_bits / max(1, C_need));
  }

  // base = floor(W / (2^K - 1))（K=0 なら使わないが 1 を置いておく）
  unsigned long long denom = (K >= 1) ? (pow2_ull(K) - 1ULL) : 1ULL;
  if (denom == 0ULL) denom = 1ULL;
  unsigned long long base_ull = (K >= 1 ? (W / denom) : 0ULL);
  long long base = (long long)((K >= 1) ? max(1ULL, base_ull) : 1ULL);

  // 微調整粒度 g = base / 2^d（2 枚/山 で期待残差 ~ base/4 を消し切る目安 ⇒ d=3）
  int d = (K >= 1 ? 3 : 0);
  long long g = (long long)max(1ULL, (unsigned long long)base >> d);

  // ---- A 構築 ----
  vector<long long> A; A.reserve(N);
  vector<int> idx_L; idx_L.reserve(fixed_L);
  for (int j = 0; j < fixed_L; ++j) { idx_L.push_back((int)A.size()); A.push_back(L); }

  // 残差ビット：i=0..K-1、各段 q_i = min(C_need, 残り) 枚
  vector<vector<int>> idx_bit(K);
  vector<long long> w(K, 1);
  for (int i = 0; i < K; ++i) {
    __int128 w128 = ( (__int128)base ) * ( (__int128)pow2_ull(i) );
    unsigned long long w_ull = (w128 > (__int128)ULLONG_MAX ? ULLONG_MAX : (unsigned long long)w128);
    long long wi = (long long)min<unsigned long long>(w_ull, (unsigned long long)U);
    if (wi < 1) wi = 1;
    w[i] = wi;

    int quota = min(C_need, max(0, free_for_bits - (int)(A.size() - fixed_L)));
    int put = min(quota, N - (int)A.size());
    idx_bit[i].reserve(put);
    for (int t = 0; t < put; ++t) {
      idx_bit[i].push_back((int)A.size());
      A.push_back(wi);
    }
  }

  // 微調整 g を R_fine 枚
  vector<int> idx_fine;
  for (int t = 0; t < R_fine && (int)A.size() < N; ++t) {
    idx_fine.push_back((int)A.size());
    A.push_back(g);
  }
  // 念のため埋まっていなければ g で埋める
  while ((int)A.size() < N) {
    idx_fine.push_back((int)A.size());
    A.push_back(g);
  }

  // ---- A を 1 行出力 ----
  for (int i = 0; i < N; ++i) { if (i) cout << ' '; cout << A[i]; }
  cout << '\n' << flush;

  // ---- B を読む ----
  vector<long long> B(M, 0);
  for (int j = 0; j < M; ++j) { if (!(cin >> B[j])) B[j] = 0; }

  // ---- 2) 割当（需要整合 + L1 減少） ----
  vector<int> X(N, 0);
  vector<long long> S(M, 0);

  // まず L を各山に 1 枚ずつ
  for (int j = 0; j < (int)idx_L.size() && j < M; ++j) {
    int id = idx_L[j]; X[id] = j + 1; S[j] += A[id];
  }

  // 目標ビット列 t_j を先に決める（需要を確定）
  vector<unsigned long long> t(M, 0);
  if (K >= 1) {
    for (int j = 0; j < M; ++j) {
      long long delta = B[j] - L; // 期待残差
      if (delta < 0) delta = 0;
      if ((unsigned long long)delta > W) delta = (long long)W;
      unsigned __int128 num = (unsigned __int128)( (unsigned long long)delta ) + (unsigned long long)(base / 2);
      unsigned long long tt = (base > 0) ? (unsigned long long)( num / (unsigned long long)base ) : 0ULL;
      unsigned long long maxT = (K >= 63) ? ((1ULL<<62)-1ULL) : (pow2_ull(K) - 1ULL);
      if (tt > maxT) tt = maxT;
      t[j] = tt;
    }
  }

  // 各ビット段 i について、希望者（t_j の i ビットが 1）の中から
  // 残差が大きい順に供給数の範囲で割り当て（高位→低位の順）
  for (int i = K - 1; i >= 0; --i) {
    if (idx_bit[i].empty()) continue;
    long long wi = w[i];
    // 希望者を集める
    vector<int> want;
    want.reserve(M);
    for (int j = 0; j < M; ++j) if ((t[j] >> i) & 1ULL) want.push_back(j);
    if (want.empty()) continue;

    // 今の残差で降順ソート（不足が大きい山を優先）
    sort(want.begin(), want.end(), [&](int a, int b){
      return (B[a] - S[a]) > (B[b] - S[b]);
    });

    int supply = (int)idx_bit[i].size();
    int used = 0;
    for (int k = 0; k < (int)want.size() && used < supply; ++k) {
      int j = want[k];
      long long dlt = B[j] - S[j];
      if (dlt < (wi + 1) / 2) continue; // L1 を悪化させない条件
      int id = idx_bit[i][used++];
      X[id] = j + 1;
      S[j] += wi;
    }
    // 余ったビットは捨て（X=0 のまま）
  }

  // 微調整 g を Δ ≥ g/2 の山にだけ貪欲投入（最大 Δ 優先）
  if (!idx_fine.empty() && M > 0) {
    priority_queue<Node, vector<Node>, Cmp> pq;
    for (int j = 0; j < M; ++j) {
      long long dlt = B[j] - S[j];
      if (dlt >= (g + 1) / 2) pq.push(Node{dlt, j});
    }
    for (int id : idx_fine) {
      if (pq.empty()) break;
      Node top = pq.top(); pq.pop();
      if (top.d < (g + 1) / 2) break;
      int j = top.j;
      X[id] = j + 1;
      S[j] += g;
      long long nd = B[j] - S[j];
      if (nd >= (g + 1) / 2) pq.push(Node{nd, j});
    }
  }

  // ---- X を 1 行出力 ----
  for (int i = 0; i < N; ++i) {
    if (X[i] < 0 || X[i] > M) X[i] = 0;
    if (i) cout << ' ';
    cout << X[i];
  }
  cout << '\n' << flush;

  return 0;
}
