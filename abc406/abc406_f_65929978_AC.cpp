/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65929978
 * Submitted at: 2025-05-17 23:41:41
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_f
 * Result: AC
 * Execution Time: 662 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

using S = ll;
S op(S l, S r) {
  return l + r;
}
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> graph(n);
  vector<P> edges(n - 1);
  segtree<S, op, e> seg(n * 2);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    edges[i] = {a, b};
  }

  vector<ll> in(n), out(n), depth(n, 0);
  ll cnt   = 0;
  auto dfs = [&](auto&& f, ll v, ll p) -> void {
    seg.set(cnt, 1);
    in[v] = cnt++;
    if(p != -1) depth[v] = depth[p] + 1;
    for(auto nv: graph[v]) {
      if(nv == p) continue;
      f(f, nv, v);
    }
    out[v] = cnt++;
  };
  dfs(dfs, 0, -1);

  ll q, w_sum = n;
  cin >> q;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll x, w;
      cin >> x >> w;
      x--;
      w_sum += w;
      seg.set(in[x], seg.get(in[x]) + w);
    } else {
      ll y;
      cin >> y;
      y--;
      auto [u, v] = edges[y];
      ll deep     = depth[u] > depth[v] ? u : v;
      cout << abs(w_sum - 2 * seg.prod(in[deep], out[deep])) << endl;
    }
  }

  return 0;
}
