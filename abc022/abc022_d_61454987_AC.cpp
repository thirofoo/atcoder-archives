/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc022/submissions/61454987
 * Submitted at: 2025-01-07 16:31:37
 * Problem URL: https://atcoder.jp/contests/abc022/tasks/abc022_d
 * Result: AC
 * Execution Time: 119 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; i++)

using S = ld;
S op(S l, S r) {
  return l + r;
}
S e() {
  return (ld) 0.0;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cout << setprecision(10) << fixed << endl;
  ll n;
  cin >> n;
  vector<ld> ax(n), ay(n), bx(n), by(n);
  segtree<S, op, e> sg_ax(n), sg_ay(n), sg_bx(n), sg_by(n);
  ld sum_a = 0.0, sum_b = 0.0;
  rep(i, n) {
    cin >> ax[i] >> ay[i];
    sum_a += ax[i] * ax[i] * (n - 1);
    sum_a -= 2.0 * ax[i] * sg_ax.prod(0, i);
    sum_a += ay[i] * ay[i] * (n - 1);
    sum_a -= 2.0 * ay[i] * sg_ay.prod(0, i);
    sg_ax.set(i, ax[i]);
    sg_ay.set(i, ay[i]);
  }
  rep(i, n) {
    cin >> bx[i] >> by[i];
    sum_b += bx[i] * bx[i] * (n - 1);
    sum_b -= 2.0 * bx[i] * sg_bx.prod(0, i);
    sum_b += by[i] * by[i] * (n - 1);
    sum_b -= 2.0 * by[i] * sg_by.prod(0, i);
    sg_bx.set(i, bx[i]);
    sg_by.set(i, by[i]);
  }
  // cerr << sum_a << " " << sum_b << endl;
  ld ans = sum_b / sum_a;
  cout << sqrt(ans) << endl;

  return 0;
}