/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65923698
 * Submitted at: 2025-05-17 22:39:23
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_f
 * Result: WA
 * Execution Time: 797 ms
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

using S = long long;
S Sum_e() {
  return 0;
}
S Sum_op(S a, S b) {
  return a + b;
}

using U = pair<int, int>;
U Min_e() {
  return pair(1e9, 1e9);
}
U Min_op(U a, U b) {
  return min(a, b);
}

class EulerTour {
  public:
  EulerTour(): n(0), turn(0) {}
  explicit EulerTour(const int &_n) {
    n    = _n;
    turn = 0;
    Graph.assign(n, {});
    vw.assign(n, 0);
    finish.assign(n, 0);
    discover.assign(n, 0);
    v_cost1     = segtree<S, Sum_op, Sum_e>(2 * n);
    e_cost1     = segtree<S, Sum_op, Sum_e>(2 * n);
    v_cost2     = segtree<S, Sum_op, Sum_e>(2 * n);
    e_cost2     = segtree<S, Sum_op, Sum_e>(2 * n);
    depth_visit = segtree<U, Min_op, Min_e>(2 * n);
  }

  inline void addEdge(const int &u, const int &v, const long long &w) {
    Graph[u].emplace_back(pair(v, w));
    Graph[v].emplace_back(pair(u, w));
  }

  inline void addVCost(const int &i, const int &w) {
    // vw[i] = w;
    v_cost1.set(discover[i], w);
    v_cost2.set(discover[i], w);
    v_cost2.set(finish[i], -w);
  }

  inline void changeECost(int u, int v, const int &nw) {
    // ※ Graph自体の更新はしていない
    if(discover[u] > discover[v]) swap(u, v);
    // 辺は2回しか通らない → O(logN)で更新可
    e_cost1.set(discover[v], nw);
    e_cost2.set(discover[v], nw);
    e_cost2.set(finish[v], -nw);
  }

  inline S distV(const int &u, const int &v) {
    return rootV(u) + rootV(v) - 2 * rootV(lca(u, v)) + vw[lca(u, v)];
  }
  inline S distE(const int &u, const int &v) {
    return rootE(u) + rootE(v) - 2 * rootE(lca(u, v));
  }
  inline S partV(const int &root) {
    return v_cost1.prod(discover[root], finish[root]);
  }
  inline S partE(const int &root) {
    return e_cost1.prod(discover[root] + 1, finish[root]);
  }

  inline int lca(int u, int v) {
    if(u == v) return u;
    if(discover[u] > discover[v]) swap(u, v);
    return depth_visit.prod(discover[u], finish[v] + 1).second;
  }

  inline void build() {
    dfs(0, -1, 0, 0);
  }

  private:
  int n, turn;
  vector<vector<pair<int, long long>>> Graph;
  segtree<S, Sum_op, Sum_e> v_cost1, e_cost1, v_cost2, e_cost2;
  segtree<U, Min_op, Min_e> depth_visit;
  vector<long long> vw, discover, finish;

  // 0 → v の頂点・辺cost
  inline long long rootV(const int &v) {
    return v_cost2.prod(0, discover[v] + 1);
  }
  inline long long rootE(const int &v) {
    return e_cost2.prod(1, discover[v] + 1);
  }

  void dfs(const int &now, const int &pre, const int &w, const int &d) {
    // 行きがけ処理
    discover[now] = turn;
    depth_visit.set(turn, U(d, now));
    v_cost1.set(turn, vw[now]);
    v_cost2.set(turn, vw[now]);
    e_cost1.set(turn, w);
    e_cost2.set(turn, w);
    turn++;
    for(auto &&[next, nw]: Graph[now]) {
      if(next == pre) continue;
      dfs(next, now, nw, d + 1);
    }
    // 帰りがけ処理
    finish[now] = turn;
    if(pre != -1) depth_visit.set(turn, U(d - 1, pre));
    v_cost1.set(turn, 0);
    e_cost1.set(turn, 0);
    v_cost2.set(turn, -vw[now]);
    e_cost2.set(turn, -w);
    turn++;
  }
};

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  EulerTour euler(n);
  vector<vector<ll>> graph(n);
  using P = pair<ll, ll>;
  vector<P> edges(n - 1);
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    edges[i] = P(u, v);
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
    euler.addEdge(u, v, 0);
  }
  rep(i, n) euler.addVCost(i, 1);
  euler.build();

  // 0 を root として depth, 部分木のサイズを計算
  vector<ll> depth(n, 0), part_size(n, 1);
  auto dfs = [&](auto self, ll v, ll pre) -> void {
    depth[v] = (pre == -1 ? 0 : depth[pre] + 1);
    for(auto to: graph[v]) {
      if(to == pre) continue;
      self(self, to, v);
      part_size[v] += part_size[to];
    }
  };
  dfs(dfs, 0, -1);

  // rep(i, n) cerr << depth[i] << " ";
  // cerr << endl;
  // rep(i, n) cerr << part_size[i] << " ";
  // cerr << endl;

  ll q, w_sum = 0;
  vector<ll> weights(n, 1);
  cin >> q;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, w;
      cin >> x >> w;
      x--;
      w_sum += w;
      weights[x] += w;
      euler.addVCost(x, weights[x]);
    } else {
      ll y;
      cin >> y;
      y--;
      auto [u, v] = edges[y];
      ll deep     = (depth[u] > depth[v] ? u : v);
      cout << abs(w_sum - euler.partV(deep)) << endl;
    }
  }

  return 0;
}