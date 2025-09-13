/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69273560
 * Submitted at: 2025-09-13 19:17:38
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: WA
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  long long L, U;
  if (!(cin >> N >> M >> L >> U)) return 0;

  // -------------------------------
  // 1) カード値 A_i の設計
  // -------------------------------
  vector<long long> A;
  A.reserve(N);

  // K = 各山に用意する二進重みの枚数
  int K = (M == 0 ? 0 : (N / M));
  if (K < 0) K = 0;
  if (K > 60) K = 60; // 念のため（2^K の安全閾）

  auto safe_mul = [](long long a, long long b) -> long long {
    __int128 z = ( __int128 )a * ( __int128 )b;
    if (z < 1) z = 1;
    if (z > LLONG_MAX) z = LLONG_MAX;
    return (long long)z;
  };

  auto pow2_ll = [](int e)->long long {
    if (e >= 62) return (1LL<<61); // guard
    return (1LL << e);
  };

  if (K >= 1) {
    // base = floor(U / (2^K - 1)) で、bit[0..K-1] の最大総和が ~U
    unsigned long long denom = (1ULL << K) - 1ULL;
    if (denom == 0ULL) denom = 1ULL;
    long long base = (long long)(U / (long long)denom);
    if (base < 1) base = 1;

    // (山ごとに K ビット) × M = M*K 枚を優先的に作る（総 N が許す限り）
    // 配列の順序は [山0のbit0..bitK-1][山1のbit0..] … とする必要は無いが、
    // 後段で重み別に処理しやすいよう、「bitごとに M 枚」を繰り返し追加する。
    // => インデックスを重み別で保持するので順序は自由。
    vector<vector<int>> idx_of_weight(K); // 各bit(=重み)のカードのインデックス
    for (int i = 0; i < K; ++i) {
      long long w = safe_mul(base, pow2_ll(i));
      if (w > U) w = U; // 安全側（理論上ここは超えないが保険）
      for (int j = 0; j < M && (int)A.size() < N; ++j) {
        idx_of_weight[i].push_back((int)A.size());
        A.push_back(w);
      }
    }

    // 余剰カード R は base を細分化した「微調整用」に割り当て（大小バランス良く）
    int R = N - (int)A.size();
    long long fine = max(1LL, base / 2); // base/2 から刻んでいく
    while (R-- > 0) {
      A.push_back(max(1LL, fine));
      // 次は半分（大きめ→細かめの順で段階的に）
      if (fine > 1) fine = max(1LL, fine / 2);
    }
  } else {
    // N < M のように K=0 の場合：素直に幾何級数的に落とした値で N 枚用意
    long long v = U;
    for (int i = 0; i < N; ++i) {
      A.push_back(max(1LL, v));
      if (v > 1) v = max(1LL, v / 2);
    }
  }

  // A_i を行ごとに出力 & flush（必須）
  for (int i = 0; i < N; ++i) cout << A[i] << '\n';
  cout.flush();

  // -------------------------------
  // 2) 目標 B_j を取得
  // -------------------------------
  vector<long long> B(M, 0);
  for (int j = 0; j < M; ++j) {
    if (!(cin >> B[j])) B[j] = 0;
  }

  // -------------------------------
  // 3) 多山同時貪欲割当て（L1 誤差最小化志向）
  //    重いカードから順に：
  //    Δ_j = B_j - S_j が最大の山へ、かつ Δ_j >= w/2 のときのみ配る（そうでなければ捨てる）
  // -------------------------------
  vector<long long> S(M, 0); // 現在の山合計
  vector<int> X(N, 0);       // 割当て（0=捨てる, 1..M=山番号）

  // 優先度付きキューで Δ_j 最大の山を得る
  struct Node { long long d; int j; };
  struct Cmp { bool operator()(const Node& a, const Node& b) const {
    if (a.d != b.d) return a.d < b.d; // max-heap
    return a.j > b.j;
  }};

  auto assign_weight_list = [&](const vector<int>& idxs, long long w) {
    if (idxs.empty()) return;
    priority_queue<Node, vector<Node>, Cmp> pq;
    for (int j = 0; j < M; ++j) pq.push(Node{B[j] - S[j], j});

    for (int id : idxs) {
      if (pq.empty()) { /* 全捨て */ continue; }

      Node top = pq.top(); pq.pop();
      // 改善条件: |d - w| < |d| <=> d >= w/2（d>=0の場合）
      // d<0（既に超過）の山に足すのは L1 を悪化させるので不可
      if (top.d * 2 >= w) {
        // この山に加える
        S[top.j] += w;
        X[id] = top.j + 1;
        // 新しい d を push
        pq.push(Node{B[top.j] - S[top.j], top.j});
      } else {
        // この重みを足せる山は存在しない（top が最大 Δ_j なので）
        // => 残りの同重みカードは全部捨てるのが最善
        // 今回のカードも捨て
        X[id] = 0;
        // 残りカードも捨て打ちして break してよいが、
        // 一応ループ継続でも計算量は十分小さい（ここでは break で高速化）
        // 残りは全部捨てる
        // （重みが大きすぎる段階での「全捨て」判断）
        for (int k = &id - &idxs[0] + 1; k < (int)idxs.size(); ++k) X[idxs[k]] = 0;
        break;
      }
    }
  };

  // 重み別インデックスの復元（A 配列を走査して値毎に束ねる）
  // ここでは「同じ値のカードをまとめて」重い値から順に処理する。
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j){
    if (A[i] != A[j]) return A[i] > A[j]; // 降順
    return i < j;
  });

  for (int l = 0; l < N; ) {
    int r = l;
    while (r < N && A[ord[r]] == A[ord[l]]) ++r;
    long long w = A[ord[l]];
    vector<int> idxs;
    idxs.reserve(r - l);
    for (int t = l; t < r; ++t) idxs.push_back(ord[t]);
    assign_weight_list(idxs, w);
    l = r;
  }

  // -------------------------------
  // 4) 割当て出力（各行 + flush 必須）
  // -------------------------------
  for (int i = 0; i < N; ++i) cout << X[i] << '\n';
  cout.flush();

  return 0;
}
