/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64767502
 * Submitted at: 2025-04-12 21:45:02
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_e
 * Result: AC
 * Execution Time: 298 ms
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

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  segtree<S, op, e> seg(n + 1);
  dsu uf(n);
  rep(i, n) {
    seg.set(i, 0);
    for(auto v: g[i]) {
      if(v > i) seg.set(v, 1);
      else uf.merge(i, v);
    }
    cout << (uf.size(0) == i + 1 ? seg.prod(0, n) : -1) << endl;
  }

  return 0;
}