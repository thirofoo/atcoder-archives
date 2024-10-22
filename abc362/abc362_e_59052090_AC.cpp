/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/59052090
 * Submitted at: 2024-10-22 14:10:42
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_e
 * Result: AC
 * Execution Time: 162 ms
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
  if(n == 1) return cout << n << endl, 0;

  vector dp(n + 1, vector(n, vector(n, vector<mint>(n + 1, 0))));
  rep(i, n) for(ll j = i + 1; j < n; j++) dp[j][j][i][2] = 1;

  rep(i, n) rep(j, n) rep(k, n) {
    rep(l, n) {
      // i 番目を考慮しない時
      dp[i + 1][j][k][l] += dp[i][j][k][l];
      // i 番目を考慮する時
      if(i > j && j > k && a[i] - a[j] == a[j] - a[k]) {
        dp[i + 1][i][j][l + 1] += dp[i][j][k][l];
      }
    }
  }
  cout << n << " ";
  for(ll i = 2; i <= n; i++) {
    mint ans = 0;
    rep(j, n) rep(k, n) ans += dp[n][j][k][i];
    cout << ans.val() << " ";
  }
  cout << endl;

  return 0;
}
