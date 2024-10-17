/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/58876530
 * Submitted at: 2024-10-17 15:59:27
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_e
 * Result: AC
 * Execution Time: 125 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

#include <atcoder/all>
using mint = atcoder::modint998244353;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m, k, s, t, x;
  cin >> n >> m >> k >> s >> t >> x;
  s--, t--, x--;
  vector<ll> u(m), v(m);
  rep(i, m) cin >> u[i] >> v[i], u[i]--, v[i]--;
  vector dp(n, vector<mint>(2, 0));
  dp[s][(s == x)] = 1;
  rep(i, k) {
    vector next_dp(n, vector<mint>(2, 0));
    rep(j, m) rep(l, 2) {
      next_dp[u[j]][(l + (u[j] == x)) % 2] += dp[v[j]][l];
      next_dp[v[j]][(l + (v[j] == x)) % 2] += dp[u[j]][l];
    }
    swap(dp, next_dp);
  }
  cout << dp[t][0].val() << endl;

  return 0;
}
