/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc011/submissions/61492995
 * Submitted at: 2025-01-09 15:59:20
 * Problem URL: https://atcoder.jp/contests/abc011/tasks/abc011_4
 * Result: RE
 * Execution Time: 558 ms
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

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  using ld = long double;

  cout << setprecision(15) << fixed;
  ll n, d, x, y;
  cin >> n >> d >> x >> y;
  if(((x % d) + d) % d != 0 || ((y % d) + d) % d != 0) {
    cout << (ld) 0.0 << "\n";
    return 0;
  }
  ll op_x = x / d, op_y = y / d;
  ll op_rest = n - abs(op_x) - abs(op_y);
  if(op_rest < 0 || op_rest % 2 != 0) {
    cout << (ld) 0.0 << "\n";
    return 0;
  }

  vector nCk_exp2(n + 1, vector<ld>(n + 1));
  nCk_exp2[0][0] = 1.0;
  rep(i, n) rep(j, n) {
    nCk_exp2[i + 1][j] += nCk_exp2[i][j] / 2.0;
    nCk_exp2[i + 1][j + 1] += nCk_exp2[i][j] / 2.0;
  }
  ld ans = 0.0;
  for(ll add_x = 0; add_x <= op_rest; add_x += 2) {
    ll sum_x = op_x + add_x, sum_y = n - sum_x, add_y = op_rest - add_x;
    ans += nCk_exp2[n][sum_x] * nCk_exp2[sum_x][add_x / 2] * nCk_exp2[sum_y][add_y / 2];
    // cerr << sum_x << " " << sum_y << " " << add_x << " " << add_y << endl;
  }
  cout << ans << "\n";

  return 0;
}