/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67777879
 * Submitted at: 2025-07-20 15:53:39
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * Result: AC
 * Execution Time: 763 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

using S = struct {
  ll llen, rlen, max, size;
};
S op(S l, S r) {
  S res;
  res.llen = l.llen + (l.llen == l.size ? r.llen : 0);
  res.rlen = r.rlen + (r.rlen == r.size ? l.rlen : 0);
  res.size = l.size + r.size;
  res.max  = max({l.max, r.max, l.rlen + r.llen});
  return res;
}
S e() {
  return {0, 0, 0, 0};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<S, op, e> sg(n - 1);
  rep(i, n - 1) {
    ll v = s[i] == s[i + 1];
    sg.set(i, S{v, v, v, 1});
  }

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll i;
      char x;
      cin >> i >> x;
      i--;
      s[i] = x;
      if(i > 0) {
        ll v1 = s[i - 1] == s[i];
        sg.set(i - 1, S{v1, v1, v1, 1});
      }
      if(i < n - 1) {
        ll v2 = s[i] == s[i + 1];
        sg.set(i, S{v2, v2, v2, 1});
      }
    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      cout << sg.prod(l, r).max + 1 << endl;
    }
  }

  return 0;
}
