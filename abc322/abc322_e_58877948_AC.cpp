/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/58877948
 * Submitted at: 2024-10-17 16:51:22
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_e
 * Result: AC
 * Execution Time: 427 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k, p;
  cin >> n >> k >> p;
  vector<ll> cost(n);
  vector delta(n, vector<ll>(k, 0));
  rep(i, n) {
    cin >> cost[i];
    rep(j, k) cin >> delta[i][j];
  }
  vector dp(n + 1, map<vector<ll>, ll>{});
  dp[0][vector<ll>(k, 0)] = 0;
  rep(i, n) {
    for(auto [key, value]: dp[i]) {
      // 開発しない場合
      if(!dp[i + 1].count(key)) dp[i + 1][key] = INF;
      dp[i + 1][key] = min(dp[i + 1][key], value);

      // 開発する場合
      vector<ll> next_param   = key;
      rep(j, k) next_param[j] = min(p, next_param[j] + delta[i][j]);
      if(!dp[i + 1].count(next_param)) dp[i + 1][next_param] = INF;
      dp[i + 1][next_param] = min(dp[i + 1][next_param], value + cost[i]);
    }
  }
  cout << (!dp[n].count(vector<ll>(k, p)) ? -1 : dp[n][vector<ll>(k, p)]) << endl;

  return 0;
}
