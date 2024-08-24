/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57052908
 * Submitted at: 2024-08-24 21:21:48
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_d
 * Result: WA
 * Execution Time: 2209 ms
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

struct Edge {
  ll to;
};
using Graph = vector<vector<Edge>>;
struct LCA {
  vector<vector<int>> parent;
  vector<int> dist;
  LCA(const Graph &G, int root = 0) {
    init(G, root);
  }
  // 初期化
  void init(const Graph &G, int root = 0) {
    int V = G.size();
    int K = 1;
    while((1 << K) < V) K++;
    // parent[i][j] : 2^i先の親
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for(int k = 0; k + 1 < K; k++) {
      for(int v = 0; v < V; v++) {
        if(parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }
  void dfs(const Graph &G, int v, int p, int d) {
    parent[0][v] = p;
    dist[v]      = d;
    for(auto e: G[v]) {
      if(e.to != p) dfs(G, e.to, v, d + 1);
    }
  }
  int query(int u, int v) {
    if(dist[u] < dist[v]) swap(u, v);
    int K = parent.size();
    for(int k = 0; k < K; k++) {
      if((dist[u] - dist[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    if(u == v) return u;
    for(int k = K - 1; k >= 0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  Graph graph(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(Edge{b});
    graph[b].push_back(Edge{a});
  }
  vector<ll> v(k);
  rep(i, k) {
    cin >> v[i];
    v[i]--;
  }
  LCA lca(graph);
  ll total_lca            = v[0];
  rep(i, k - 1) total_lca = lca.query(total_lca, v[i + 1]);

  queue<ll> que;
  vector<ll> dist(n, -1);
  que.push(0);
  dist[0] = 0;
  while(!que.empty()) {
    ll now = que.front();
    que.pop();
    for(auto &&e: graph[now]) {
      if(dist[e.to] != -1) continue;
      dist[e.to] = dist[now] + 1;
      que.push(e.to);
    }
  }

  ll ans = 0;
  vector<bool> visited(n, false);
  rep(i, k) {
    ll now = v[i];
    while(!visited[now] && now != total_lca) {
      visited[now] = true;
      now          = lca.query(now, total_lca);
      // 親 (一番浅い頂点) に移動
      ll parent = -1, depth = INF;
      for(auto &&e: graph[now]) {
        if(dist[e.to] < depth) {
          depth  = dist[e.to];
          parent = e.to;
        }
      }
      now = parent;
      ans++;
    }
  }
  cout << ans + 1 << '\n';

  return 0;
}