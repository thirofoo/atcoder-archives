/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc402/submissions/65082731
 * Submitted at: 2025-04-21 18:39:20
 * Problem URL: https://atcoder.jp/contests/abc402/tasks/abc402_e
 * Result: AC
 * Execution Time: 50 ms
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

  cout << fixed << setprecision(15);
  using ld = long double;

  ll n, x;
  cin >> n >> x;
  vector<ld> s(n), c(n), p(n);
  rep(i, n) {
    cin >> s[i] >> c[i] >> p[i];
    p[i] /= 100.0;
  }
  vector<vector<ld>> dp(x + 1, vector<ld>((1LL << n), 0.0));
  // dp[i][j] := 残り所持金 i 円・既に正解した問題の集合 j の時の得点期待値
  rep(i, x + 1) rep(j, (1LL << n)) {
    rep(k, n) {
      if((j & (1LL << k)) == 0) continue;
      if(i - c[k] < 0) continue;
      ld val   = (dp[i - c[k]][j ^ (1LL << k)] + s[k]) * p[k] + dp[i - c[k]][j] * (1.0 - p[k]);
      dp[i][j] = max(dp[i][j], val);
    }
  }
  cout << dp[x][(1LL << n) - 1] << endl;

  return 0;
}
