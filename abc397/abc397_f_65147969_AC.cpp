/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65147969
 * Submitted at: 2025-04-24 00:14:14
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_f
 * Result: AC
 * Execution Time: 1440 ms
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
  return {l.size + r.size, max(l.val, r.val)};
}
S mapping(F f, S x) {
  return {x.size, x.val + f};
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
  vector<vector<ll>> idx(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    idx[a[i]].emplace_back(-i);
  }
  rep(i, n) {
    sort(idx[i].begin(), idx[i].end());
    idx[i].emplace_back(1);
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
  vector<ll> cnt(n, 0);
  ll variety = 0;
  rep(i, n - 1) {
    if(cnt[a[i]] == 0) variety++;
    cnt[a[i]]++;
    seg.set(i + 1, {1, variety});
  }
  vector<ll> right_variety(n, 0);
  cnt.assign(n, 0);
  variety = 0;
  for(ll i = n - 1; i > 0; i--) {
    if(cnt[a[i]] == 0) variety++;
    cnt[a[i]]++;
    right_variety[i] = variety;
  }

  rep(i, n) cerr << seg.get(i).val << " ";
  cerr << endl;
  rep(i, n) cerr << right_variety[i] << " ";
  cerr << endl;

  ll ans = 0;
  for(ll i = 1; i < n - 1; i++) {
    ll prev_idx = -(*upper_bound(idx[a[i]].begin(), idx[a[i]].end(), -i)) + 1;
    seg.apply(prev_idx, i + 1, 1);

    S cand = seg.prod(0, i + 1);
    ans    = max(ans, cand.val + right_variety[i + 1]);

    // cerr << "i: " << i << " cand: " << cand.val << " right_variety: " << right_variety[i + 1] << endl;
    // cerr << "prev_idx: " << -(*upper_bound(idx[a[i]].begin(), idx[a[i]].end(), -i)) + 1 << endl;
    // rep(j, n) cerr << seg.get(j).val << " ";
    // cerr << endl;
  }
  cout << ans << endl;

  return 0;
}