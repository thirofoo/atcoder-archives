/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/tessoku-book/submissions/55923915
 * Submitted at: 2024-07-24 16:07:26
 * Problem URL: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl
 * Result: AC
 * Execution Time: 43 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n, m; cin >> n >> m;
  using P = pair<ll, ll>;
  vector<vector<P>> graph(n);
  for(int i = 0; i < m; i++) {
    ll a, b, c; cin >> a >> b >> c;
    a--, b--;
    graph[a].emplace_back(pair(b, c));
    graph[b].emplace_back(pair(a, c));
  }
  priority_queue<P, vector<P>, greater<P>> pq;
  vector<ll> dist(n, INF);
  pq.push(pair(0, 0));
  while(!pq.empty()) {
    auto [d, v] = pq.top(); pq.pop();
    if(dist[v] != INF) continue;
    dist[v] = d;
    for(auto &&[nv, nd] : graph[v]) {
      if(dist[nv] != INF) continue;
      pq.push(pair(d + nd, nv));
    }
  }
  for(int i = 0; i < n; i++) {
    if(dist[i] == INF) cout << -1 << '\n';
    else cout << dist[i] << '\n';
  }
  
  return 0;
}