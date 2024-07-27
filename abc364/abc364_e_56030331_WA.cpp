/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56030331
 * Submitted at: 2024-07-27 21:35:36
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_e
 * Result: WA
 * Execution Time: 333 ms
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

  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector dp(n + 1, vector(n + 1, vector(x + 2, INF)));
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, n) {
      rep(k, x + 1) {
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if(j + 1 <= n && dp[i][j][k] <= y) {
          dp[i + 1][j + 1][min(x + 1, k + a[i])] = min(dp[i + 1][j + 1][min(x + 1, k + a[i])], dp[i][j][k] + b[i]);
        }
      }
    }
  }
  ll ans = 0;
  rep(i, n + 1) {
    rep(j, x + 2) {
      if(dp[n][i][j] == INF) continue;
      ans = max(ans, i);
    }
  }
  cout << ans << '\n';

  return 0;
}