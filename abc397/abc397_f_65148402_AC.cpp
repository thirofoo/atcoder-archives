/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65148402
 * Submitted at: 2025-04-24 00:38:44
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_f
 * Result: AC
 * Execution Time: 363 ms
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
using T0 = ll;
using S0 = T0;
S0 op0(S0 x, S0 y) {
  return max(x, y);
}
S0 e0() {
  return -T0(0LL);
}
using F0 = T0;
S0 act0(F0 f, S0 x) {
  return f + x;
}
F0 comp0(F0 f, F0 g) {
  return f + g;
}
F0 id0() {
  return T0(0LL);
}
#define Add_Max_monoid S0, op0, e0, F0, act0, comp0, id0

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> st;
  vector<ll> r_variety(n + 1, 0);
  for(ll i = n - 1; i >= 0; i--) {
    st.insert(a[i]);
    r_variety[i] = st.size();
  }

  st.clear();
  vector<ll> prev(n + 1, -1);
  // ※ 2 区間利用することでどれだけ増加させられるかを持つイメージ
  lazy_segtree<Add_Max_monoid> seg(n);
  ll ans = 0;
  rep(i, n - 1) {
    st.insert(a[i]);
    if(prev[a[i]] != -1) seg.apply(prev[a[i]] + 1, i + 1, 1);
    ans        = max(ans, (ll) st.size() + seg.prod(0, i + 1) + r_variety[i + 1]);
    prev[a[i]] = i;
  }
  cout << ans << endl;

  return 0;
}