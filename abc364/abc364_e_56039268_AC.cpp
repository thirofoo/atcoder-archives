/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56039268
 * Submitted at: 2024-07-27 21:54:05
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_e
 * Result: AC
 * Execution Time: 405 ms
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

  ll n, x, y;
  cin >> n >> x >> y;
  vector<pair<ll, ll>> ele;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    ele.emplace_back(pair(a, b));
  }
  sort(ele.begin(), ele.end());
  vector dp(n + 1, vector(n + 1, vector(x + 2, INF)));
  dp[0][0][0] = 0;
  rep(i, n) {
    auto [a, b] = ele[i];
    rep(j, n) {
      rep(k, x + 2) {
        if(dp[i][j][k] == INF) continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if(k <= x && dp[i][j][k] <= y) {
          dp[i + 1][j + 1][min(x + 1, k + a)] = min(dp[i + 1][j + 1][min(x + 1, k + a)], dp[i][j][k] + b);
        }
      }
    }
  }
  ll ans = 0;
  rep(j, n + 1) {
    rep(k, x + 2) {
      if(dp[n][j][k] == INF) continue;
      ans = max(ans, j);
    }
  }
  dp.assign(n + 1, vector(n + 1, vector(y + 2, INF)));
  dp[0][0][0] = 0;
  sort(ele.begin(), ele.end(), [](auto a, auto b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });
  rep(i, n) {
    auto [a, b] = ele[i];
    rep(j, n) {
      rep(k, y + 2) {
        if(dp[i][j][k] == INF) continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if(k <= y && dp[i][j][k] <= x) {
          dp[i + 1][j + 1][min(y + 1, k + b)] = min(dp[i + 1][j + 1][min(y + 1, k + b)], dp[i][j][k] + a);
        }
      }
    }
  }
  rep(j, n + 1) {
    rep(k, y + 2) {
      if(dp[n][j][k] == INF) continue;
      ans = max(ans, j);
    }
  }
  cout << ans << '\n';

  return 0;
}