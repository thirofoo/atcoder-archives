/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69342166
 * Submitted at: 2025-09-14 22:21:32
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_e
 * Result: TLE
 * Execution Time: 2211 ms
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

using S = struct {
  ll val, size, l, r, bit_cnt;
};
S op(S l, S r) {
  S res;
  res.val     = l.val + r.val + l.l * r.size + l.size * r.r;
  res.size    = l.size + r.size;
  res.l       = r.l + r.bit_cnt * l.size + l.l;
  res.r       = l.r + l.bit_cnt * r.size + r.r;
  res.bit_cnt = l.bit_cnt + r.bit_cnt;
  return res;
}
S e() {
  return S{0, 0, 0, 0, 0};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n), l(q), r(q);
  vector<vector<ll>> idx(101);
  rep(i, n) {
    cin >> a[i];
    idx[a[i]].emplace_back(i);
  }
  rep(i, q) cin >> l[i] >> r[i];

  vector<ll> ans(q, 0);
  segtree<S, op, e> seg(n);
  rep(i, n) seg.set(i, S{0, 1, 0, 0, 0});

  for(ll i = 1; i <= 100; i++) {
    for(auto t: idx[i]) seg.set(t, S{1, 1, 1, 1, 1});
    rep(j, q) {
      ans[j] += seg.prod(l[j] - 1, r[j]).val * i;
      auto x = seg.prod(l[j] - 1, r[j]);
      // if(i <= 3) cerr << x.val << " " << x.size << " " << x.l << " " << x.r << " " << x.bit_cnt << " | ";
    }
    // if(i <= 3) cerr << endl;
    for(auto t: idx[i]) seg.set(t, S{0, 1, 0, 0, 0});
  }
  for(auto x: ans) cout << x << "\n";

  return 0;
}
