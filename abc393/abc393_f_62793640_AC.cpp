/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc393/submissions/62793640
 * Submitted at: 2025-02-15 21:44:32
 * Problem URL: https://atcoder.jp/contests/abc393/tasks/abc393_f
 * Result: AC
 * Execution Time: 296 ms
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
  return max(l, r);
}
S e() {
  return 0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n), comp;
  rep(i, n) {
    cin >> a[i];
    comp.emplace_back(a[i]);
  }

  using T = tuple<ll, ll, ll>;
  vector<T> queries;
  rep(i, q) {
    ll r, x;
    cin >> r >> x;
    queries.push_back({r, x, i});
    comp.emplace_back(x);
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  rep(i, n) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
  using P        = pair<ll, ll>;
  vector<vector<P>> queries2(n);
  rep(i, q) {
    auto [r, x, idx] = queries[i];
    queries2[r - 1].emplace_back(x, idx);
  }

  vector<ll> ans(q, -1);
  segtree<S, op, e> seg(comp.size());
  rep(i, n) {
    seg.set(a[i], seg.prod(0, a[i]) + 1);
    for(auto [x, idx]: queries2[i]) {
      ans[idx] = seg.prod(0, lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1);
    }
  }
  rep(i, q) cout << ans[i] << '\n';

  return 0;
}