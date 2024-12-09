/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60601599
 * Submitted at: 2024-12-09 11:55:43
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_d
 * Result: AC
 * Execution Time: 1124 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

using S = ll;
S op(S l, S r) {
  return l + r;
}
S e() {
  return 0;
}
ll V;
bool f(S a) {
  return a < V;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n), rui_a(n + 1, 0);
  rep(i, n) {
    cin >> a[i];
    rui_a[i + 1] = rui_a[i] + a[i];
  }
  segtree<S, op, e> seg(a);

  vector<ll> ans(n);
  rep(i, n) {
    V       = a[i];
    ll left = i, right = i + 1;
    while(true) {
      ll next_l = seg.min_left<f>(left);
      ll next_r = seg.max_right<f>(right);
      if(next_l == left && next_r == right) break;

      V     = rui_a[next_r] - rui_a[next_l];
      left  = next_l;
      right = next_r;
    }
    ans[i] = (right - left == n ? seg.all_prod() : seg.prod(left, right));
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}
