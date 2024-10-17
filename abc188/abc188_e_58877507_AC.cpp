/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc188/submissions/58877507
 * Submitted at: 2024-10-17 16:37:24
 * Problem URL: https://atcoder.jp/contests/abc188/tasks/abc188_e
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> graph(n);
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    graph[x].emplace_back(y);
  }
  vector<ll> dp(n, INF);
  rep(i, n) for(auto to: graph[i]) dp[to] = min(dp[to], min(dp[i], a[i]));

  ll ans = -INF;
  
  rep(i, n) ans = max(ans, a[i] - dp[i]);
  cout << ans << '\n';

  return 0;
}
