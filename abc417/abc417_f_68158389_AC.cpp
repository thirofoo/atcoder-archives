/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc417/submissions/68158389
 * Submitted at: 2025-08-02 22:28:39
 * Problem URL: https://atcoder.jp/contests/abc417/tasks/abc417_f
 * Result: AC
 * Execution Time: 518 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

struct S {
  mint sum;
  int size;
};
using F = optional<mint>;
S op(S a, S b) {
  return {a.sum + b.sum, a.size + b.size};
}
S e() {
  return {0, 0};
}
S mapping(F f, S s) {
  if(f.has_value()) {
    return {f.value() * s.size, s.size};
  }
  return s;
}
F composition(F f_new, F f_old) {
  if(f_new.has_value()) {
    return f_new;
  }
  return f_old;
}
F id() {
  return nullopt;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<S> init(n);
  rep(i, n) {
    cin >> a[i];
    init[i] = {mint(a[i]), 1};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    l--;
    S v      = seg.prod(l, r);
    mint sum = v.sum;
    mint num = v.size;
    mint exp = sum * num.inv();
    seg.apply(l, r, F{exp});
  }

  rep(i, n) cout << seg.get(i).sum.val() << " ";
  cout << endl;

  return 0;
}