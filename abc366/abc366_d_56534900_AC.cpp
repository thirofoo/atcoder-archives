/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56534900
 * Submitted at: 2024-08-10 21:17:18
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_d
 * Result: AC
 * Execution Time: 91 ms
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

  ll n;
  cin >> n;
  // 3 次元累積和
  vector a(n + 1, vector(n + 1, vector<ll>(n + 1, 0)));
  rep(i, n) rep(j, n) rep(k, n) cin >> a[i + 1][j + 1][k + 1];
  rep(i, n + 1) rep(j, n + 1) rep(k, n) a[i][j][k + 1] += a[i][j][k];
  rep(i, n + 1) rep(j, n + 1) rep(k, n) a[i][k + 1][j] += a[i][k][j];
  rep(i, n + 1) rep(j, n + 1) rep(k, n) a[k + 1][i][j] += a[k][i][j];

  // rep(i, n + 1) {
  //   rep(j, n + 1) {
  //     rep(k, n + 1) {
  //       cerr << a[i][j][k] << ' ';
  //     }
  //     cerr << '\n';
  //   }
  //   cerr << '\n';
  // }

  ll q;
  cin >> q;
  while(q--) {
    ll lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    lx--;
    ly--;
    lz--;
    cout << a[rx][ry][rz] - a[lx][ry][rz] - a[rx][ly][rz] - a[rx][ry][lz] + a[lx][ly][rz] + a[lx][ry][lz] + a[rx][ly][lz] - a[lx][ly][lz] << '\n';
  }

  return 0;
}