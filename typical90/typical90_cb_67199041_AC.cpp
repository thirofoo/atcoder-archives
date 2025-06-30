/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67199041
 * Submitted at: 2025-06-30 16:48:41
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cb
 * Result: AC
 * Execution Time: 310 ms
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

  ll n, d;
  cin >> n >> d;
  vector<ll> a(n), dig(d, 0LL);
  rep(i, n) {
    cin >> a[i];
    rep(j, d) {
      if((a[i] & (1LL << j)) == 0) continue;
      dig[j] |= (1LL << i);
    }
  }
  vector<vector<ll>> dp(d + 1, vector<ll>(1LL << n, 0LL));
  dp[0][0] = 1;
  rep(i, d) {
    rep(j, (1LL << n)) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j | dig[i]] += dp[i][j];
    }
  }
  cout << dp[d][(1LL << n) - 1] << endl;

  return 0;
}