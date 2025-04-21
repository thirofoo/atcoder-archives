/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc402/submissions/65082910
 * Submitted at: 2025-04-21 18:45:52
 * Problem URL: https://atcoder.jp/contests/abc402/tasks/abc402_e
 * Result: AC
 * Execution Time: 139 ms
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
  vector<vector<ld>> dp(x + 1, vector<ld>((1LL << n), -1.0));
  // dp[i][j] := 所持金 i, 正解した集合 j とした時の得点期待値
  auto dfs = [&](auto self, ll i, ll j) -> ld {
    if(dp[i][j] >= 0.0) return dp[i][j];
    dp[i][j] = 0.0;
    rep(idx, n) {
      if(j & (1LL << idx)) continue;
      if(i - c[idx] < 0) continue;
      ld cand = (self(self, i - c[idx], j | (1LL << idx)) + s[idx]) * p[idx];
      cand += self(self, i - c[idx], j) * (1.0 - p[idx]);
      dp[i][j] = max(dp[i][j], cand);
    }
    return dp[i][j];
  };
  cout << dfs(dfs, x, 0) << endl;

  return 0;
}
