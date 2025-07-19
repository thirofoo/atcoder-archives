/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67741484
 * Submitted at: 2025-07-19 22:01:28
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_e
 * Result: AC
 * Execution Time: 544 ms
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

  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<ll> p(h + w - 1);
  rep(i, h + w - 1) cin >> p[i];

  ll left = -1, right = INF, ans = INF;
  while(right - left > 1) {
    ll mid = (left + right) / 2;
    vector<vector<ll>> dp(h, vector<ll>(w, -INF));
    dp[0][0] = a[0][0] - p[0] + mid;
    if(dp[0][0] < 0) {
      left = mid;
      continue;
    }

    rep(i, h) rep(j, w) {
      if(i == h - 1 && j == w - 1) continue;
      if(i != h - 1) {
        ll v = dp[i][j] + a[i + 1][j] - p[i + j + 1];
        if(v >= 0) dp[i + 1][j] = max(dp[i + 1][j], v);
      }
      if(j != w - 1) {
        ll v = dp[i][j] + a[i][j + 1] - p[i + j + 1];
        if(v >= 0) dp[i][j + 1] = max(dp[i][j + 1], v);
      }
    }
    if(dp[h - 1][w - 1] >= 0) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;

  return 0;
}