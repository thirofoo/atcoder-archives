/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc382/submissions/60345029
 * Submitted at: 2024-11-30 22:35:44
 * Problem URL: https://atcoder.jp/contests/abc382/tasks/abc382_f
 * Result: AC
 * Execution Time: 460 ms
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

using S = struct {
  ll max;
  ll size;
};
using F = optional<ll>;

S op(S l, S r) {
  return {max(l.max, r.max), l.size + r.size};
}

S mapping(F f, S x) {
  if(f.has_value()) {
    return {f.value(), x.size};
  }
  return x;
}

F composition(F f, F g) {
  if(f.has_value()) {
    return f;
  }
  return g;
}

S e() {
  return {0, 0};
}
F id() {
  return nullopt;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using T = tuple<ll, ll, ll, ll>;
  ll h, w, n;
  cin >> h >> w >> n;
  vector<T> b;
  rep(i, n) {
    ll r, c, l;
    cin >> r >> c >> l;
    b.emplace_back(i, r, c, l);
  }
  sort(b.begin(), b.end(), [](T l, T r) {
    auto [i1, r1, c1, l1] = l;
    auto [i2, r2, c2, l2] = r;
    return r1 > r2;
  });

  vector<ll> ans(n, -1);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(w + 1);
  rep(i, n) {
    auto [idx, r, c, l] = b[i];
    auto [max, val]     = seg.prod(c, c + l);
    ans[idx]            = h - max;
    seg.apply(c, c + l, max + 1);
    // rep(j, 10) cerr << seg.get(j).max << " ";
    // cerr << '\n';
  }
  rep(i, n) cout << ans[i] << '\n';

  return 0;
}