/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60551936
 * Submitted at: 2024-12-08 00:57:10
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_f
 * Result: AC
 * Execution Time: 101 ms
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

  ll n, x, k;
  cin >> n >> x >> k;
  vector<ll> p(n), u(n), c(n);
  // 座標圧縮 (配列 a がある想定)
  vector<ll> comp;
  rep(i, n) {
    cin >> p[i] >> u[i] >> c[i];
    comp.emplace_back(c[i]);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  vector<vector<ll>> colors(comp.size());
  rep(i, n) {
    c[i] = lower_bound(comp.begin(), comp.end(), c[i]) - comp.begin();
    colors[c[i]].emplace_back(i);
  }
  vector<vector<ll>> dp(comp.size() + 1, vector<ll>(x + 1, -INF));
  dp[0][0] = 0;
  for(ll i = 1; i <= comp.size(); i++) {
    for(auto &&idx: colors[i - 1]) {
      for(ll j = x; j >= 0; j--) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if(j - p[idx] >= 0) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - p[idx]] + u[idx] + k);
          dp[i][j] = max(dp[i][j], dp[i][j - p[idx]] + u[idx]);
        }
      }
    }
  }
  ll ans = 0;
  rep(i, comp.size() + 1) {
    rep(j, x + 1) ans = max(ans, dp[i][j]);
  }
  cout << ans << '\n';

  return 0;
}