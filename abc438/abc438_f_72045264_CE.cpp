/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/72045264
 * Submitted at: 2025-12-27 22:38:43
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_f
 * Result: CE
 * Execution Time: None ms
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
  LCA(const Graph &G, int root = 0) { init(G, root); }
  // 初期化
  void init(const Graph &G, int root = 0) {
    int V = G.size();
    int K = 1;
    while ((1 << K) < V) K++;
    // parent[i][j] : 2^i先の親
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for (int k = 0; k + 1 < K; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }
  void dfs(const Graph &G, int v, int p, int d) {
    parent[0][v] = p;
    dist[v] = d;
    for (auto e : G[v]) {
      if (e.to != p) dfs(G, e.to, v, d + 1);
    }
  }
  int query(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    int K = parent.size();
    for (int k = 0; k < K; k++) {
      if ((dist[u] - dist[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
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

  ll n;
  cin >> n;
  Graph g(n);
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    g[u].emplace_back({v});
    g[v].emplace_back({u});
  }

  LCA lca(g, 0);
  vector<ll> sz(n, 0);
  auto dfs = [&](auto&& self, ll v, ll p) -> void {
    sz[v] = 1;
    for(auto &e : g[v]) {
      if (e.to == p) continue;
      self(self, e.to, v);
      sz[v] += sz[e.to];
    }
  };
  dfs(dfs, 0, -1);

  auto get_dist = [&](ll u, ll v) {
    return lca.dist[u] + lca.dist[v] - 2 * lca.dist[lca.query(u, v)];
  };

  ll ans = 0;
  ll l = 0, r = 0;
  bool ok = true;

  rep(k, n) {
    ll next = k; 
    if (k > 0) {
      ll dl = get_dist(l, next), dr = get_dist(r, next), dlr = get_dist(l, r);
      if (dl + dr == dlr) {
        // ok
      } else if (dl + dlr == dr) l = next;
      else if (dr + dlr == dl) r = next;
      else ok = false;
    }
    if (!ok) break;

    ll cnt = 0;
    if (l == r) {
      cnt = n * (n + 1) / 2;
      for(auto &e : g[l]) {
        ll s;
        if (lca.dist[e.to] < lca.dist[l]) s = n - sz[l];
        else s = sz[e.to];
        cnt -= s * (s + 1) / 2;
      }
    } else {
      ll w = lca.query(l, r), sl, sr;
      if (l == w) {
        ll child = lca.up(r, lca.dist[r] - lca.dist[l] - 1);
        sl = n - sz[child];
      } else sl = sz[l];
      if (r == w) {
        ll child = lca.up(l, lca.dist[l] - lca.dist[r] - 1);
        sr = n - sz[child];
      } else sr = sz[r];

      cnt = sl * sr;
    }
    ans += cnt;
  }
  cout << ans << "\n";

  return 0;
}