/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc094/submissions/61353434
 * Submitted at: 2025-01-04 14:39:40
 * Problem URL: https://atcoder.jp/contests/arc094/tasks/arc094_c
 * Result: RE
 * Execution Time: 1813 ms
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

  ll n;
  cin >> n;
  vector<ll> a, b;
  ll rest = 0, add = 0;
  rep(i, n) {
    ll ta, tb;
    cin >> ta >> tb;
    if(ta <= tb) {
      rest += tb - ta;
      add += ta;
    } else {
      a.emplace_back(ta);
      b.emplace_back(tb);
    }
  }
  vector dp(a.size() + 1, vector<ll>(rest + 1, -INF));
  dp[0][0] = 0;
  rep(i, a.size()) rep(j, rest + 1) {
    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    if(rest - j > a[i] - b[i]) {
      dp[i + 1][j + a[i] - b[i]] = max(dp[i + 1][j + a[i] - b[i]], dp[i][j] + a[i]);
    }
  }
  ll ans = 0;
  rep(i, a.size()) rep(j, rest + 1) {
    ans = max(ans, add + dp[i][j] + rest - j);
  }
  cout << ans << endl;

  return 0;
}