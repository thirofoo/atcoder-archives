/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61563642
 * Submitted at: 2025-01-11 21:20:20
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_d
 * Result: AC
 * Execution Time: 243 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  rep(i, n) {
    ll right = min(a[i] + seg.get(i).val + i + 1, n);
    seg.apply(i, right, 1);
    cout << (a[i] + seg.get(i).val) - (right - i) << " ";
  }
  cout << endl;

  return 0;
}