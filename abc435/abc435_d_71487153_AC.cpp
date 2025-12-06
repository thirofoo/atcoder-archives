/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71487153
 * Submitted at: 2025-12-06 21:19:55
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_d
 * Result: AC
 * Execution Time: 168 ms
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
  scc_graph g(n);
  using P = pair<ll, ll>;
  vector<P> edges;
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    edges.emplace_back(x, y);
    g.add_edge(x, y);
  }
  auto scc = g.scc();
  vector<ll> comp_id(n);
  rep(i, scc.size()) {
    for(auto v: scc[i]) {
      comp_id[v] = i;
    }
  }
  vector<vector<ll>> graph(scc.size());
  for(auto [x, y]: edges) {
    ll cx = comp_id[x];
    ll cy = comp_id[y];
    if(cx != cy) {
      graph[cy].push_back(cx);
    }
  }
  rep(i, scc.size()) {
    sort(graph[i].begin(), graph[i].end());
    graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
  }

  ll q;
  cin >> q;
  vector<bool> visited(scc.size(), false);
  queue<ll> que;
  while(q--) {
    ll t, v;
    cin >> t >> v;
    v--;
    if(t == 1) {
      ll cv = comp_id[v];
      if(visited[cv]) continue;
      que.push(cv);
      visited[cv] = true;
      while(!que.empty()) {
        ll u = que.front();
        que.pop();
        for(auto nv: graph[u]) {
          if(!visited[nv]) {
            visited[nv] = true;
            que.push(nv);
          }
        }
      }
      ll cnt = 0;
      rep(i, scc.size()) {
        if(visited[i]) cnt++;
      }
    } else {
      cout << (visited[comp_id[v]] ? "Yes" : "No") << "\n";
    }
  }

  return 0;
}