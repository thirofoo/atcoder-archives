/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60601538
 * Submitted at: 2024-12-09 11:51:09
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_d
 * Result: AC
 * Execution Time: 1189 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  segtree<S, op, e> seg(a);

  vector<ll> ans(n);
  rep(i, n) {
    V       = a[i];
    ll left = i, right = i + 1;
    while(true) {
      ll next_l = seg.min_left(left, f);
      ll next_r = seg.max_right(right, f);
      if(next_l == left && next_r == right) break;

      V += seg.prod(next_l, left) + seg.prod(right, next_r);
      left  = next_l;
      right = next_r;
    }
    ans[i] = (right - left == n ? seg.all_prod() : seg.prod(left, right));
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}
