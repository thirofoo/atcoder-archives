/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69273720
 * Submitted at: 2025-09-13 19:22:38
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: AC
 * Execution Time: 36 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  long long L, U;
  if (!(cin >> N >> M >> L >> U)) return 0;

  // 1) パック設計：各山あたり (1 枚の L) + (K_res 枚のビット)
  int K_res = 0;
  if (M > 0) K_res = N / M - 1;        // 1 枚を L に使う
  if (K_res < 0) K_res = 0;
  if (K_res > 60) K_res = 60;          // 安全上限

  auto pow2_ll = [](int e)->unsigned long long {
    if (e >= 63) return (1ULL << 62);  // ガード
    return (1ULL << e);
  };

  // base = floor((U-L) / (2^K_res - 1)) で [L, U] をちょうど覆う
  unsigned long long W = (U >= L) ? (unsigned long long)(U - L) : 0ULL;
  unsigned long long denom = (K_res >= 1) ? (pow2_ll(K_res) - 1ULL) : 1ULL;
  if (denom == 0ULL) denom = 1ULL;
  unsigned long long base_ull = (denom ? (W / denom) : 0ULL);
  long long base = (long long)max(1ULL, base_ull); // 最低 1

  vector<long long> A;
  A.reserve(N);

  // A[0..M-1] = L（各山に 1 枚）
  vector<int> idx_offset; idx_offset.reserve(M);
  for (int j = 0; j < M && (int)A.size() < N; ++j) {
    idx_offset.push_back((int)A.size());
    A.push_back(L);
  }

  // 残差用ビット：i=0..K_res-1 について、それぞれ M 枚ずつ base * (1<<i)
  // （A の並びは [L×M] → [bit0×M] → [bit1×M] → ...）
  vector<vector<int>> idx_bit(K_res, vector<int>(M, -1));
  for (int i = 0; i < K_res; ++i) {
    unsigned long long w_ull = (unsigned long long)base * pow2_ll(i);
    long long w = (long long)min<unsigned long long>(w_ull, (unsigned long long)U);
    if (w < 1) w = 1;
    for (int j = 0; j < M && (int)A.size() < N; ++j) {
      idx_bit[i][j] = (int)A.size();
      A.push_back(w);
    }
  }

  // 余りカードがあれば微小重みで埋める（なくてもOK）
  while ((int)A.size() < N) {
    long long w = max(1LL, base / 2);
    A.push_back(w);
  }

  // A_i を 1 行ずつ出力 & flush（必須）
  for (int i = 0; i < N; ++i) cout << A[i] << " ";
  cout << '\n' << flush;

  // 2) B の入力
  vector<long long> B(M, 0);
  for (int j = 0; j < M; ++j) {
    if (!(cin >> B[j])) B[j] = 0;
  }

  // 3) 割当て X：各山に L を 1 枚、残差は四捨五入でビット化
  vector<int> X(N, 0);

  // 各山に L を 1 枚ずつ割り当て（idx_offset[j] が j の L）
  for (int j = 0; j < M && j < (int)idx_offset.size(); ++j) {
    int id = idx_offset[j];
    if (id >= 0) X[id] = j + 1;
  }

  // t_j = round((B_j - L)/base) を [0, 2^K_res -1] にクランプ
  unsigned long long maxT = (K_res >= 63) ? (1ULL << 62) - 1ULL : (pow2_ll(K_res) - 1ULL);
  for (int j = 0; j < M; ++j) {
    long long delta = B[j] - L;                      // ∈ [0, W]
    if (delta < 0) delta = 0;
    if ((unsigned long long)delta > W) delta = (long long)W;

    // 整数で四捨五入: (delta + base/2) / base
    unsigned __int128 num = (unsigned __int128)( (base > 0) ? ( (unsigned long long)delta + (unsigned long long)(base/2) ) : 0ULL );
    unsigned long long t = (base > 0) ? (unsigned long long)( num / (unsigned long long)base ) : 0ULL;
    if (t > maxT) t = maxT;

    // ビットごとに割当て
    for (int i = 0; i < K_res; ++i) {
      int id = (j < M && i < (int)idx_bit.size()) ? idx_bit[i][j] : -1;
      if (id < 0) continue;
      if ((t >> i) & 1ULL) X[id] = j + 1; // 使う
      else X[id] = 0;                     // 捨てる
    }
  }

  // 4) X を 1 行ずつ出力 & flush
  for (int i = 0; i < N; ++i) cout << X[i] << " ";
  cout << '\n' << flush;

  return 0;
}
