/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc369/submissions/61051767
 * Submitted at: 2024-12-24 14:33:17
 * Problem URL: https://atcoder.jp/contests/abc369/tasks/abc369_d
 * Result: AC
 * Execution Time: 35 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector dp(n + 1, vector<ll>(2, -INF));
  dp[0][0] = 0;
  rep(i, n) {
    dp[i + 1][0] = max(dp[i][0], dp[i][1] + 2 * a[i]);
    dp[i + 1][1] = max(dp[i][1], dp[i][0] + a[i]);
  }
  cout << max(dp[n][0], dp[n][1]) << '\n';

  return 0;
}