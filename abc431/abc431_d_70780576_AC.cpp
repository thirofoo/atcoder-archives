/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70780576
 * Submitted at: 2025-11-08 21:24:52
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_d
 * Result: AC
 * Execution Time: 654 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
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
  vector<ll> w(n), h(n), b(n);
  ll sum = 0;
  rep(i, n) {
    cin >> w[i] >> h[i] >> b[i];
    sum += w[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, -INF));
  dp[0][0] = 0;
  rep(i, n) {
    rep(j, sum + 1) {
      dp[i + 1][j]        = max(dp[i + 1][j], dp[i][j] + b[i]);
      dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + h[i]);
    }
  }
  ll ans = -INF;
  for(ll i = 0; i <= sum / 2; i++) ans = max(ans, dp[n][i]);
  cout << ans << "\n";

  return 0;
}