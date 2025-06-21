/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66979585
 * Submitted at: 2025-06-21 22:38:33
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_f
 * Result: WA
 * Execution Time: 4418 ms
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

  ll n, m;
  cin >> n >> m;
  using P = pair<ll, ll>;
  vector<P> edges(m);
  vector<set<ll>> g(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].insert(v);
    g[v].insert(u);
    edges[i] = {u, v};
  }

  ll q;
  cin >> q;
  dsu uf(n);
  vector<ll> x(q);
  ll ans = m;
  rep(i, q) {
    cin >> x[i];
    x[i]--;
    auto [u, v] = edges[x[i]];
    if(!uf.same(u, v) && g[u].count(v)) {
      ll u_lead = uf.leader(u);
      ll v_lead = uf.leader(v);
      uf.merge(u, v);
      if(g[u_lead].size() > g[v_lead].size() && v_lead == uf.leader(u)) {
        swap(g[u_lead], g[v_lead]);
      }
      for(auto to: g[u_lead]) {
        if(g[v_lead].count(to)) {
          ans--;
          g[to].erase(u_lead);
        } else g[v_lead].insert(to);
      }
      if(g[u_lead].count(u_lead)) g[u_lead].erase(u_lead);
      if(g[u_lead].count(v_lead)) g[u_lead].erase(v_lead);
      g[v_lead].clear();
      ans--;
    }
    cout << ans << endl;
    // rep(j, n) {
    //   cerr << "j = " << j + 1 << " : ";
    //   for(auto it = g[j].begin(); it != g[j].end(); it++) {
    //     cerr << *it + 1 << " ";
    //   }
    //   cerr << endl;
    // }
    // cerr << endl;
  }

  return 0;
}