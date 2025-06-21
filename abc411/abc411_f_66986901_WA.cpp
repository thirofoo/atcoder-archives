/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66986901
 * Submitted at: 2025-06-22 02:00:47
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_f
 * Result: WA
 * Execution Time: 453 ms
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
      if(g[u_lead].size() < g[v_lead].size()) swap(u_lead, v_lead);
      uf.merge(u_lead, v_lead); // 第一引数が次のリーダーになる

      for(auto to: g[v_lead]) {
        g[to].erase(v_lead);
        if(g[u_lead].count(to)) {
          ans--;
        } else if(to != u_lead) {
          g[u_lead].insert(to);
          g[to].insert(u_lead);
        }
      }
      ans--;
      g[v_lead].clear();
    }
    cout << ans << '\n';
  }

  return 0;
}