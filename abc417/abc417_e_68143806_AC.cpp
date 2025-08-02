/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68143806
 * Submitted at: 2025-08-02 21:54:14
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_e
 * Result: AC
 * Execution Time: 272 ms
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

  ll t;
  cin >> t;
  dsu uf;

  while(t--) {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<ll>> g(n);
    rep(i, m) {
      ll u, v;
      cin >> u >> v;
      u--, v--;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }

    ll now = x;
    vector<bool> deleted(n, false);
    vector<ll> ans;
    while(true) {
      ans.emplace_back(now + 1);
      deleted[now] = true;
      uf           = dsu(n);
      rep(i, n) {
        if(deleted[i]) continue;
        for(auto to: g[i]) {
          if(deleted[to]) continue;
          uf.merge(i, to);
        }
      }

      ll cand = INF;
      for(auto to: g[now]) {
        if(deleted[to] || !uf.same(to, y)) continue;
        cand = min(cand, to);
      }
      if(cand == INF) break;
      now = cand;
    }
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
  }

  return 0;
}