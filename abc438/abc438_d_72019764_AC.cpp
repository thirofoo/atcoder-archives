/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/72019764
 * Submitted at: 2025-12-27 21:30:34
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_d
 * Result: AC
 * Execution Time: 90 ms
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
  ll val, idx;
};
S op(S l, S r) {
  S res;
  res.val = max(l.val, r.val);
  res.idx = (l.val >= r.val) ? l.idx : r.idx;
  return res;
}
S e() {
  return {-INF, -1};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n), rui_a(n + 1), rui_b(n + 1), rui_c(n + 1), rui_b_c(n + 1);
  rep(i, n) {
    cin >> a[i];
    rui_a[i + 1] = rui_a[i] + a[i];
  }
  rep(i, n) {
    cin >> b[i];
    rui_b[i + 1] = rui_b[i] + b[i];
  }
  rep(i, n) {
    cin >> c[i];
    rui_c[i + 1]   = rui_c[i] + c[i];
    rui_b_c[i + 1] = rui_b_c[i] + (b[i] - c[i]);
  }
  segtree<S, op, e> seg(n + 1);
  rep(i, n + 1) seg.set(i, {rui_b_c[i], i});

  ll ans = -INF;
  for(ll x = 1; x < n - 1; x++) {
    S tmp  = seg.prod(x + 1, n);
    ll val = rui_a[x] + (rui_b[tmp.idx] - rui_b[x]) + (rui_c[n] - rui_c[tmp.idx]);
    // cerr << "rui_a[x]: " << rui_a[x] << ", rui_b[tmp.idx] - rui_b[x]: " << (rui_b[tmp.idx] - rui_b[x]) << ", rui_c[n] - rui_c[tmp.idx]: " << (rui_c[n] - rui_c[tmp.idx]) << "\n";
    // cerr << "x: " << x << ", idx: " << tmp.idx << ", val: " << val << "\n\n";
    ans = max(ans, val);
  }
  cout << ans << "\n";

  return 0;
}