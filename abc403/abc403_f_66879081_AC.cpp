/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/66879081
 * Submitted at: 2025-06-19 16:05:15
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_f
 * Result: AC
 * Execution Time: 54 ms
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

  vector dp(2001, vector<string>(2, ""));
  // dp[i][j] : i を形成する & 外側に足し算が存在する最小長の文字列
  dp[1][0]    = "1";
  dp[11][0]   = "11";
  dp[111][0]  = "111";
  dp[1111][0] = "1111";
  for(ll i = 1; i <= n; i++) {   // 足されたり掛けられたりする数 i
    for(ll j = 1; j <= i; j++) { // 足したり掛けたりする数 j
      if(i + j <= 2000) {
        string cand = "";
        if(dp[i][1] == "") cand += dp[i][0];
        else if(dp[i][0] == "") cand += dp[i][1];
        else if(dp[i][0].size() < dp[i][1].size()) cand += dp[i][0];
        else cand += dp[i][1];

        cand += "+";

        if(dp[j][1] == "") cand += dp[j][0];
        else if(dp[j][0] == "") cand += dp[j][1];
        else if(dp[j][0].size() < dp[j][1].size()) cand += dp[j][0];
        else cand += dp[j][1];

        if(dp[i + j][1] == "" || dp[i + j][1].size() > cand.size()) dp[i + j][1] = cand;
      }
      if(i * j <= 2000) {
        string cand = "";

        if(dp[i][1] == "") cand += dp[i][0];
        else if(dp[i][0] == "") cand += "(" + dp[i][1] + ")";
        else if((ll) dp[i][1].size() + 2 < (ll) dp[i][0].size()) cand += "(" + dp[i][1] + ")";
        else cand += dp[i][0];

        cand += "*";

        if(dp[j][1] == "") cand += dp[j][0];
        else if(dp[j][0] == "") cand += "(" + dp[j][1] + ")";
        else if((ll) dp[j][1].size() + 2 < (ll) dp[j][0].size()) cand += "(" + dp[j][1] + ")";
        else cand += dp[j][0];

        if(dp[i * j][0] == "" || dp[i * j][0].size() > cand.size()) dp[i * j][0] = cand;
      }
    }
    // cerr << "dp[" << i << "][0] = " << dp[i][0] << endl;
    // cerr << "dp[" << i << "][1] = " << dp[i][1] << endl << endl;
  }
  if(dp[n][1] == "") cout << dp[n][0] << endl;
  else if(dp[n][0] == "") cout << dp[n][1] << endl;
  else if(dp[n][0].size() < dp[n][1].size()) cout << dp[n][0] << endl;
  else cout << dp[n][1] << endl;

  return 0;
}
