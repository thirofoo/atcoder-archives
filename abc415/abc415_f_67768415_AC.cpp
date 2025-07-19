/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67768415
 * Submitted at: 2025-07-20 03:24:27
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_f
 * Result: AC
 * Execution Time: 770 ms
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

using S = struct {
  ll left_len, right_len, size, max_len;
  char left_ch, right_ch;
};
S op(S l, S r) {
  S res;
  res.left_ch  = l.left_ch;
  res.right_ch = r.right_ch;
  res.size     = l.size + r.size;

  res.left_len    = l.left_len;
  res.right_len   = r.right_len;
  bool all_same_l = l.left_len == l.size;
  bool all_same_r = r.right_len == r.size;
  if(all_same_l && l.right_ch == r.left_ch) {
    res.left_len = l.left_len + r.left_len;
  }
  if(all_same_r && l.right_ch == r.left_ch) {
    res.right_len = l.right_len + r.right_len;
  }
  res.max_len = max({l.max_len, r.max_len, res.left_len, res.right_len, l.right_ch == r.left_ch ? l.right_len + r.left_len : 0LL});
  return res;
}
S e() {
  return S{0, 0, 0, 0, '\0', '\0'};
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segtree<S, op, e> sg(n);
  rep(i, n) sg.set(i, S{1, 1, 1, 1, s[i], s[i]});

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll i;
      char x;
      cin >> i >> x;
      i--;
      sg.set(i, S{1, 1, 1, 1, x, x});
    } else {
      ll l, r;
      cin >> l >> r;
      l--;
      S res = sg.prod(l, r);
      cout << res.max_len << endl;
    }
  }

  return 0;
}
