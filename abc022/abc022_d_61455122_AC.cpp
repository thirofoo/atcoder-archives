/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc022/submissions/61455122
 * Submitted at: 2025-01-07 16:37:38
 * Problem URL: https://atcoder.jp/contests/abc022/tasks/abc022_d
 * Result: AC
 * Execution Time: 60 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // 解説 AC
  // 不変量を探す (並行移動・回転移動によっても変わらない量)
  // 今回は重心からの距離の総和などがある

  cout << setprecision(10) << fixed << endl;
  ll n;
  cin >> n;
  vector<ld> ax(n), ay(n), bx(n), by(n);
  ld zax = 0.0, zay = 0.0, zbx = 0.0, zby = 0.0;
  rep(i, n) {
    cin >> ax[i] >> ay[i];
    zax += ax[i];
    zay += ay[i];
  }
  rep(i, n) {
    cin >> bx[i] >> by[i];
    zbx += bx[i];
    zby += by[i];
  }
  zax /= n, zay /= n, zbx /= n, zby /= n;
  ld sum_a = 0.0, sum_b = 0.0;
  rep(i, n) {
    sum_a += sqrt((ax[i] - zax) * (ax[i] - zax) + (ay[i] - zay) * (ay[i] - zay));
    sum_b += sqrt((bx[i] - zbx) * (bx[i] - zbx) + (by[i] - zby) * (by[i] - zby));
  }
  ld ans = sum_b / sum_a;
  cout << ans << endl;

  return 0;
}