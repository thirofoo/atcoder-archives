/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56811906
 * Submitted at: 2024-08-17 21:42:32
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_e
 * Result: AC
 * Execution Time: 902 ms
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

  ll n, k;
  cin >> n >> k;
  vector<ll> x(n), a(n);
  rep(i, n) {
    cin >> x[i];
    x[i]--;
  }
  rep(i, n) cin >> a[i];
  // ダブリング
  vector<vector<ll>> dp(60, vector<ll>(n, -1));
  rep(i, n) dp[0][i] = x[i];
  rep(i, 59) rep(j, n) {
    dp[i + 1][j] = dp[i][dp[i][j]];
  }
  vector<ll> b(n, -1);
  rep(i, n) {
    ll p = i;
    for(ll j = 0; j < 60; j++) {
      if((k >> j) & 1) p = dp[j][p];
    }
    b[i] = p;
  }
  rep(i, n) cout << a[b[i]] << (i == n - 1 ? '\n' : ' ');

  return 0;
}