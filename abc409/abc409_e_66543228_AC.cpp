/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66543228
 * Submitted at: 2025-06-07 21:34:10
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_e
 * Result: AC
 * Execution Time: 34 ms
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
  vector<ll> x(n);
  rep(i, n) cin >> x[i];
  using P = pair<ll, ll>;
  vector<vector<P>> g(n);
  rep(i, n - 1) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  ll ans   = 0;
  auto dfs = [&](auto self, ll v, ll p, ll cost) -> ll {
    ll res = x[v];
    for(auto [u, w]: g[v]) {
      if(u == p) continue;
      res += self(self, u, v, w);
    }
    ans += abs(res) * cost;
    return res;
  };
  dfs(dfs, 0, -1, 0);
  cout << ans << endl;

  return 0;
}