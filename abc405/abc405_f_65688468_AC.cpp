/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65688468
 * Submitted at: 2025-05-10 22:24:34
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_f
 * Result: AC
 * Execution Time: 639 ms
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

  using P = pair<ll, ll>;
  vector<vector<P>> in(2 * n), out(2 * n);
  vector<ll> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    in[a[i]].emplace_back(b[i], i);
    out[b[i]].emplace_back(a[i], i);
  }
  ll q;
  cin >> q;
  vector<ll> c(q), d(q);
  rep(i, q) {
    cin >> c[i] >> d[i];
    c[i]--;
    d[i]--;
    in[c[i]].emplace_back(d[i], i);
    out[d[i]].emplace_back(c[i], i);
  }

  vector<ll> ans(q, 0);
  segtree<S, op, e> seg(2 * n);
  rep(i, 2 * n) {
    if(i % 2 == 0) { // query
      for(auto [to, idx]: in[i]) {
        ans[idx] += seg.prod(i, to);
        // cerr << "i: " << i << ", to: " << to << ", idx: " << idx << ", ans[idx]: " << ans[idx] << endl;
      }
    } else {
      for(auto [to, _]: in[i]) {
        seg.set(to, seg.get(to) + 1);
        // cerr << "i: " << i << ", to: " << to << ", seg.get(to): " << seg.get(to) << endl;
      }
      for(auto [to, _]: out[i]) seg.set(i, seg.get(i) - 1);
    }
  }

  // cerr << "----------------" << endl;
  seg = segtree<S, op, e>(2 * n);
  for(ll i = 2 * n - 1; i >= 0; i--) {
    if(i % 2 == 0) { // query
      for(auto [to, idx]: out[i]) {
        ans[idx] += seg.prod(to, i);
        // cerr << "i: " << i << ", to: " << to << ", idx: " << idx << ", ans[idx]: " << ans[idx] << endl;
      }
    } else {
      for(auto [to, _]: out[i]) {
        seg.set(to, seg.get(to) + 1);
        // cerr << "i: " << i << ", to: " << to << ", seg.get(to): " << seg.get(to) << endl;
      }
      for(auto [to, _]: in[i]) seg.set(i, seg.get(i) - 1);
    }
  }
  rep(i, q) cout << ans[i] << endl;

  return 0;
}