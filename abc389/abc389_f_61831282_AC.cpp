/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61831282
 * Submitted at: 2025-01-18 22:30:23
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_f
 * Result: AC
 * Execution Time: 819 ms
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

// ========== 区間和・区間加算 ========== //
using S = struct {
  ll size;
  ll val;
};
using F = ll;
S op(S l, S r) {
  return {l.size + r.size, l.val + r.val};
}
S mapping(F f, S x) {
  return {x.size, x.val + f * x.size};
}
S e() {
  return {1, 0};
}
F composition(F f, F g) {
  return f + g;
}
F id() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(600000);
  rep(i, 600000) seg.set(i, {1, i});
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    ll l1 = 0, r1 = 600000;
    while(r1 - l1 > 1) {
      ll m1 = (l1 + r1) / 2;
      if(seg.get(m1).val < l) l1 = m1;
      else r1 = m1;
    }
    ll l2 = 0, r2 = 600000;
    while(r2 - l2 > 1) {
      ll m2 = (l2 + r2) / 2;
      if(seg.get(m2).val <= r) l2 = m2;
      else r2 = m2;
    }
    seg.apply(l1 + 1, l2 + 1, 1);
  }
  ll q;
  cin >> q;
  while(q--) {
    ll x;
    cin >> x;
    cout << seg.get(x).val << '\n';
  }

  return 0;
}
