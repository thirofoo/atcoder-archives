/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc382/submissions/60341268
 * Submitted at: 2024-11-30 22:22:14
 * Problem URL: https://atcoder.jp/contests/abc382/tasks/abc382_e
 * Result: AC
 * Execution Time: 181 ms
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
  cout << fixed << setprecision(10);

  ll n;
  double x;
  cin >> n >> x;
  vector<double> p(n);
  rep(i, n) cin >> p[i];
  vector<vector<double>> atari(n + 1, vector<double>(n + 1, 0.0));
  atari[0][0] = 1.0;
  rep(i, n) rep(j, n) {
    atari[i + 1][j] += atari[i][j] * (100.0 - p[i]) / 100.0;
    atari[i + 1][j + 1] += atari[i][j] * p[i] / 100.0;
  }

  vector<double> dp(x + 1, 0.0);
  // dp[i] : あたりがちょうど i 回出る期待値
  dp[0] = 0.0;
  for(int i = 1; i <= x; i++) {
    for(int j = 1; j <= min((int) n, i); j++) {
      if(i - j >= x) continue;
      dp[i] += dp[i - j] * atari[n][j];
    }
    dp[i] += 1.0;
    dp[i] /= (1.0 - atari[n][0]);
    // cerr << dp[i] << " ";
  }
  // cerr << '\n';
  cout << dp[x] << '\n';

  return 0;
}