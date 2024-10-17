/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/58876001
 * Submitted at: 2024-10-17 15:33:37
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_d
 * Result: AC
 * Execution Time: 155 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector dp(n + 1, vector(x + 1, vector(y + 1, INF)));
  dp[0][0][0] = 0;
  rep(i, n) rep(j, x + 1) rep(k, y + 1) {
    dp[i + 1][min(x, j + a[i])][min(y, k + b[i])] = min(dp[i + 1][min(x, j + a[i])][min(y, k + b[i])], dp[i][j][k] + 1);
    dp[i + 1][j][k]                               = min(dp[i + 1][j][k], dp[i][j][k]);
  }
  cout << (dp[n][x][y] == INF ? -1 : dp[n][x][y]) << '\n';

  return 0;
}
