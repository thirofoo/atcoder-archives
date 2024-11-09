/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59613779
 * Submitted at: 2024-11-09 22:16:07
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_f
 * Result: AC
 * Execution Time: 529 ms
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

// SegTree に乗せる型
using S = ll;
// operator (作用素)
S op(S l, S r) {
  return max(l, r);
}
// 単位元 (op(e, a) = a)
S e() {
  return -1;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> h(n);

  rep(i, n) cin >> h[i];
  segtree<S, op, e> seg(h);

  vector<ll> bill_visible(n, 0);
  stack<ll> st;
  for(ll i = n - 1; i >= 0; i--) {
    while(!st.empty() && st.top() <= h[i]) st.pop();
    bill_visible[i] = st.size();
    st.push(h[i]);
  }
  // rep(i, n) cerr << bill_visible[i] << " ";
  // cerr << endl;

  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--;
    ll max_h = seg.prod(l + 1, r);
    if(seg.prod(r, n) < max_h) {
      cout << 0 << endl;
      continue;
    }

    ll ng = r, ok = n;
    while(ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if(seg.prod(r, mid) >= max_h) ok = mid;
      else ng = mid;
    }
    cout << bill_visible[ok - 1] + 1 << endl;
  }

  return 0;
}