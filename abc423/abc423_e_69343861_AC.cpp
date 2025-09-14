/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69343861
 * Submitted at: 2025-09-14 22:26:53
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_e
 * Result: AC
 * Execution Time: 147 ms
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
  ll val, size, l, r, sum;
};
S op(S l, S r) {
  S res;
  res.val  = l.val + r.val + l.l * r.size + l.size * r.r;
  res.size = l.size + r.size;
  res.l    = r.l + r.sum * l.size + l.l;
  res.r    = l.r + l.sum * r.size + r.r;
  res.sum  = l.sum + r.sum;

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
  rep(i, n) seg.set(i, S{a[i], 1, a[i], a[i], a[i]});

  rep(j, q) cout << seg.prod(l[j] - 1, r[j]).val << "\n";

  return 0;
}
