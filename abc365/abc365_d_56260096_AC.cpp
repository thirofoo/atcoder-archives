/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56260096
 * Submitted at: 2024-08-03 21:12:10
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_d
 * Result: AC
 * Execution Time: 13 ms
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
  string s;
  cin >> n >> s;
  vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
  // dp[i][j] : i 回目までみて高橋君の直近の手が j のときの高橋君の最大得点
  // j = 0 : R, j = 1 : P, j = 2 : S
  rep(i, n) {
    rep(j, 3) rep(k, 3) {
      if(j == k) continue;
      if(k == 0) {
        if(s[i] == 'S') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + 1);
        else if(s[i] == 'R') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j]);
      } else if(k == 1) {
        if(s[i] == 'R') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + 1);
        else if(s[i] == 'P') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j]);
      } else {
        if(s[i] == 'P') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + 1);
        else if(s[i] == 'S') dp[i + 1][k] = max(dp[i + 1][k], dp[i][j]);
      }
    }
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';

  return 0;
}