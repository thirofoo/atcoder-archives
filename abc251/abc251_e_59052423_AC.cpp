/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/59052423
 * Submitted at: 2024-10-22 14:29:17
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_e
 * Result: AC
 * Execution Time: 95 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector dp1(n + 1, vector(2, vector<ll>(2, INF))), dp2(n + 1, vector(2, vector<ll>(2, INF)));
  // dp[i][j][k] : i 番目のエサを買う時に i, i + 1 番目動物にエサを与えたか否かが j, k の最小コスト
  dp1[1][0][0] = 0;
  dp2[1][1][0] = a[0];
  for(ll i = 1; i < n - 1; i++) rep(j, 2) rep(k, 2) {
      if(j != 0) {
        // エサを買わない時
        dp1[i + 1][k][0] = min(dp1[i][j][k], dp1[i + 1][k][0]);
        dp2[i + 1][k][0] = min(dp2[i][j][k], dp2[i + 1][k][0]);
      }
      // エサを買う時
      dp1[i + 1][1][0] = min(dp1[i][j][k] + a[i], dp1[i + 1][1][0]);
      dp2[i + 1][1][0] = min(dp2[i][j][k] + a[i], dp2[i + 1][1][0]);
    }
  ll ans = INF;
  rep(j, 2) rep(k, 2) { // 最後購入する
    ans = min(ans, min(dp1[n - 1][j][k], dp2[n - 1][j][k]) + a[n - 1]);
  }
  rep(k, 2) { // 最後購入しない
    ans = min(ans, dp2[n - 1][1][k]);
  }
  cout << ans << endl;

  return 0;
}
