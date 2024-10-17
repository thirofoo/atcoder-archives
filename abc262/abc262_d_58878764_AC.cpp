/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/58878764
 * Submitted at: 2024-10-17 17:14:23
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_d
 * Result: AC
 * Execution Time: 110 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

#include <atcoder/all>
using mint = atcoder::modint998244353;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  mint ans = 0;
  for(ll k = 1; k <= n; k++) {
    vector dp(n + 1, vector(k + 1, vector<mint>(k + 2)));
    dp[0][0][0] = 1;
    rep(i, n) rep(j, k + 1) rep(l, k + 2) {
      dp[i + 1][j][l] += dp[i][j][l];
      dp[i + 1][(j + a[i]) % k][min(k + 1, l + 1)] += dp[i][j][l];
    }
    ans += dp[n][0][k];
  }
  cout << ans.val() << '\n';

  return 0;
}
