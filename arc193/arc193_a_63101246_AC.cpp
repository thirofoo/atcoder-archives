/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc193/submissions/63101246
 * Submitted at: 2025-02-23 22:26:12
 * Problem URL: https://atcoder.jp/contests/arc193/tasks/arc193_a
 * Result: AC
 * Execution Time: 425 ms
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

using S = ll;
S op(S l, S r) {
  return min(l, r);
}
S e() {
  return INF;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> w(n), l(n), r(n);
  rep(i, n) cin >> w[i];

  vector<pair<ll, ll>> l_idx, r_idx;
  rep(i, n) {
    cin >> l[i] >> r[i];
    l_idx.emplace_back(l[i], i);
    r_idx.emplace_back(r[i], i);
  }
  sort(l_idx.begin(), l_idx.end());
  sort(r_idx.begin(), r_idx.end());
  segtree<S, op, e> seg_l(n), seg_r(n);
  rep(i, n) {
    auto [li, lidx] = l_idx[i];
    auto [ri, ridx] = r_idx[i];
    seg_l.set(i, w[lidx]);
    seg_r.set(i, w[ridx]);
  }
  vector<ll> l_sort = l, r_sort = r;
  sort(l_sort.begin(), l_sort.end());
  sort(r_sort.begin(), r_sort.end());

  ll q;
  cin >> q;
  while(q--) {
    ll s, t;
    cin >> s >> t;
    s--, t--;
    if(l[s] > l[t]) swap(s, t);
    // cerr << "s: " << s << " t: " << t << endl;
    if(r[s] < l[t]) cout << w[s] + w[t] << endl;
    else {
      ll ans = INF;
      ll t1  = lower_bound(l_sort.begin(), l_sort.end(), max(r[s], r[t]) + 1) - l_sort.begin();
      if(t1 != n) ans = min(ans, w[s] + w[t] + seg_l.prod(t1, n));
      // cerr << "ans: " << ans << endl;

      ll t2 = lower_bound(r_sort.begin(), r_sort.end(), min(l[s], l[t])) - r_sort.begin();
      ans   = min(ans, w[s] + w[t] + seg_r.prod(0, t2));
      // cerr << "ans: " << ans << endl;

      ll t3 = lower_bound(l_sort.begin(), l_sort.end(), r[s] + 1) - l_sort.begin();
      ll t4 = lower_bound(r_sort.begin(), r_sort.end(), l[t]) - r_sort.begin();
      if(t3 != n) {
        ans = min(ans, w[s] + w[t] + seg_l.prod(t3, n) + seg_r.prod(0, t4));
        // cerr << "seg_l.prod(t3, n): " << seg_l.prod(t3, n) << endl;
        // cerr << "seg_r.prod(0, t4): " << seg_r.prod(0, t4) << endl;
        // cerr << "w[s]: " << w[s] << " w[t]: " << w[t] << endl;
      }

      cout << (ans == INF ? -1 : ans) << endl;
    }
  }

  return 0;
}
