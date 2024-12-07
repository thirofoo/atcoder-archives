/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc383/submissions/60544638
 * Submitted at: 2024-12-07 22:39:55
 * Problem URL: https://atcoder.jp/contests/abc383/tasks/abc383_f
 * Result: WA
 * Execution Time: 74 ms
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

  using P = pair<ll, ll>;
  vector<ll> colors_max(comp.size(), 0);
  rep(i, n) {
    c[i]             = lower_bound(comp.begin(), comp.end(), c[i]) - comp.begin();
    colors_max[c[i]] = max(colors_max[c[i]], p[i]);
  }
  vector<vector<ll>> dp(comp.size() + 1, vector<ll>(x + 1, -INF));
  dp[0][0] = 0;
  rep(i, comp.size()) {
    rep(j, x) {
      if(j + colors_max[i] > x) continue;
      dp[i + 1][j + colors_max[i]] = max(dp[i + 1][j + colors_max[i]], dp[i][j] + u[i]);
    }
  }
  ll ans = 0;
  rep(i, comp.size() + 1) {
    rep(j, x + 1) ans = max(ans, dp[i][j] + i * k);
  }
  cout << ans << '\n';

  return 0;
}