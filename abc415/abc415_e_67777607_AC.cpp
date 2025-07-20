/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67777607
 * Submitted at: 2025-07-20 15:42:01
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_e
 * Result: AC
 * Execution Time: 42 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
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

  vector<vector<ll>> dp(h, vector<ll>(w, INF));
  dp[h - 1][w - 1] = 0;
  for(ll i = h - 1; i >= 0; i--) {
    for(ll j = w - 1; j >= 0; j--) {
      if(i != h - 1) dp[i][j] = min(dp[i][j], max(dp[i + 1][j] + p[i + j + 1] - a[i + 1][j], 0LL));
      if(j != w - 1) dp[i][j] = min(dp[i][j], max(dp[i][j + 1] + p[i + j + 1] - a[i][j + 1], 0LL));
    }
  }
  cout << max(dp[0][0] + p[0] - a[0][0], 0LL) << endl;

  return 0;
}
