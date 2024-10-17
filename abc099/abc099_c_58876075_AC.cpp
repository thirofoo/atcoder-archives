/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc099/submissions/58876075
 * Submitted at: 2024-10-17 15:37:16
 * Problem URL: https://atcoder.jp/contests/abc099/tasks/abc099_c
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> coins = {1};
  rep(i, 10) {
    coins.emplace_back(pow(6, i));
    coins.emplace_back(pow(9, i));
  }

  vector<ll> dp(n + 1, INF);
  dp[0] = 0;
  rep(i, n) {
    for(auto ele: coins) {
      if(i + ele > n) continue;
      dp[i + ele] = min(dp[i + ele], dp[i] + 1);
    }
  }
  cout << dp[n] << '\n';

  return 0;
}
