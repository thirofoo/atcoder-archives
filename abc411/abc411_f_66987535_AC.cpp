/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66987535
 * Submitted at: 2025-06-22 03:08:37
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_f
 * Result: AC
 * Execution Time: 650 ms
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
    ll ru = uf.leader(u), rv = uf.leader(v);
    if(ru == rv || !g[ru].count(rv)) {
      cout << ans << "\n";
      continue;
    }
    ll new_root = uf.merge(ru, rv);
    ll old_root = (new_root == ru ? rv : ru);
    for(ll to: g[old_root]) {
      g[to].erase(old_root);
      if(g[new_root].count(to)) {
        ans--;
      } else if(to != new_root) {
        g[new_root].insert(to);
        g[to].insert(new_root);
      }
    }
    ans--;
    g[old_root].clear();
    cout << ans << "\n";
  }

  return 0;
}