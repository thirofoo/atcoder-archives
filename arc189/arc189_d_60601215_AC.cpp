/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc189/submissions/60601215
 * Submitted at: 2024-12-09 11:29:22
 * Problem URL: https://atcoder.jp/contests/arc189/tasks/arc189_d
 * Result: AC
 * Execution Time: 1218 ms
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
  return l + r;
}
S e() {
  return 0;
}
// min_left 用判別関数
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
    ll left = i, right = i + 1;
    while(true) {
      V         = seg.prod(left, right);
      ll next_l = seg.min_left(left, f);
      // cerr << "left: " << left << " next_l: " << next_l << endl;
      V += seg.prod(next_l, left);

      ll next_r = seg.max_right(right, f);
      // cerr << "right: " << right << " next_r: " << next_r << endl;
      V += seg.prod(right, next_r);
      if(next_l == left && next_r == right) break;

      left  = next_l;
      right = next_r;
    }
    ans[i] = seg.prod(left, right);
    // cerr << "\n";
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}