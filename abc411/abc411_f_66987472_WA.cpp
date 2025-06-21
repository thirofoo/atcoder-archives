/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66987472
 * Submitted at: 2025-06-22 03:02:02
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_f
 * Result: WA
 * Execution Time: 1051 ms
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
  vector<unordered_set<ll>> g(n);
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
  ll ans = m;
  rep(i, q) {
    ll x;
    cin >> x;
    x--;
    auto [u, v] = edges[x];
    ll u_lead = uf.leader(u), v_lead = uf.leader(v);
    if(g[u_lead].count(v_lead)) {
      ll big_lead   = (g[u_lead].size() >= g[v_lead].size()) ? u_lead : v_lead;
      ll small_lead = (big_lead == u_lead) ? v_lead : u_lead;

      ans--;
      if(g[big_lead].count(big_lead)) g[big_lead].erase(big_lead);
      if(g[big_lead].count(small_lead)) g[big_lead].erase(small_lead);
      if(g[small_lead].count(big_lead)) g[small_lead].erase(big_lead);
      if(g[small_lead].count(small_lead)) g[small_lead].erase(small_lead);

      for(auto to: g[small_lead]) {
        g[to].erase(small_lead);
        if(g[big_lead].count(to)) ans--;
        g[big_lead].insert(to);
        g[to].insert(big_lead);
      }

      uf.merge(big_lead, small_lead);
      if(uf.leader(big_lead) == small_lead) g[big_lead] = g[small_lead];
      g[small_lead].clear();
    }
    cout << ans << '\n';
  }

  return 0;
}