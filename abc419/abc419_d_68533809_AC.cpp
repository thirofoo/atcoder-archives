/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68533809
 * Submitted at: 2025-08-16 21:14:06
 * Problem URL: https://atcoder.jp/contests/abc419/tasks/abc419_d
 * Result: AC
 * Execution Time: 134 ms
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

  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  vector<ll> l(m), r(m);
  rep(i, m) {
    cin >> l[i] >> r[i];
    l[i]--;
    seg.apply(l[i], r[i], 1);
  }
  rep(i, n) cout << (seg.get(i).val % 2 ? t[i] : s[i]);
  cout << endl;

  return 0;
}