/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56593438
 * Submitted at: 2024-08-11 15:55:27
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_f
 * Result: WA
 * Execution Time: 43 ms
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

  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> param;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    param.emplace_back(pair{a, b});
  }
  sort(param.begin(), param.end(), [](const pair<ll, ll> &e1, const pair<ll, ll> &e2) {
    auto &[a1, b1] = e1;
    auto &[a2, b2] = e2;
    if(b1 != b2) return b1 > b2;
    else return a1 < a2;
  });
  vector dp(n + 1, vector<ll>(k + 1, -1e16));
  dp[0][0] = 1;
  rep(i, n) {
    auto &[a, b] = param[i];
    rep(j, k + 1) {
      if(dp[i][j] == -1e16) continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if(j + 1 <= k) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], a * dp[i][j] + b);
      }
    }
  }
  cout << dp[n][k] << '\n';

  return 0;
}