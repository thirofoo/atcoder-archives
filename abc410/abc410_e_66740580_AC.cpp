/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66740580
 * Submitted at: 2025-06-14 21:22:00
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_e
 * Result: AC
 * Execution Time: 51 ms
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

  ll n, h, m;
  cin >> n >> h >> m;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<vector<ll>> dp(n + 1, vector<ll>(h + 1, -1));
  dp[0][h] = m;
  rep(i, n) rep(j, h + 1) {
    if(dp[i][j] < 0) continue;
    if(j >= a[i]) dp[i + 1][j - a[i]] = max(dp[i + 1][j - a[i]], dp[i][j]);
    if(dp[i][j] - b[i] >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - b[i]);
  }
  ll ans = -1;
  rep(i, n + 1) rep(j, h + 1) {
    if(dp[i][j] >= 0) ans = max(ans, i);
  }
  cout << ans << endl;

  return 0;
}