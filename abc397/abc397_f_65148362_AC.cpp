/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65148362
 * Submitted at: 2025-04-24 00:36:01
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_f
 * Result: AC
 * Execution Time: 261 ms
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
/* verify : https://atcoder.jp/contests/arc017/tasks/arc017_4 */
using T105 = ll;
using S105 = T105;
S105 op105(S105 x, S105 y) {
  return max(x, y);
}
S105 e105() {
  return -T105(0LL);
}
using F105 = T105;
S105 act105(F105 f, S105 x) {
  return f + x;
}
F105 comp105(F105 f, F105 g) {
  return f + g;
}
F105 id105() {
  return T105(0LL);
}
#define Add_Max_monoid S105, op105, e105, F105, act105, comp105, id105

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> r_variety(n + 1, 0), cnt(n + 1, 0);
  ll variety = 0;
  for(ll i = n - 1; i >= 0; i--) {
    if(cnt[a[i]] == 0) variety++;
    cnt[a[i]]++;
    r_variety[i] = variety;
  }

  set<ll> st;
  vector<ll> prev(n + 1, -1);
  // ※ 2 区間利用することでどれだけ増加させられるかを持つイメージ
  lazy_segtree<Add_Max_monoid> seg(n);
  ll ans = 0;
  rep(i, n - 1) {
    st.insert(a[i]);
    if(prev[a[i]] != -1) seg.apply(prev[a[i]] + 1, i + 1, 1);
    // cerr << st.size() << " " << seg.prod(0, i + 1) << " " << r_variety[i + 1] << endl;
    ans        = max(ans, (ll) st.size() + seg.prod(0, i + 1) + r_variety[i + 1]);
    prev[a[i]] = i;
  }
  cout << ans << endl;

  return 0;
}