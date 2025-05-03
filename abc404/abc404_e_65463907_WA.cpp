/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65463907
 * Submitted at: 2025-05-03 22:08:44
 * Problem URL: https://atcoder.jp/contests/abc404/tasks/abc404_e
 * Result: WA
 * Execution Time: 2 ms
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
  vector<ll> c(n, 0), a(n, 0);
  rep(i, n - 1) cin >> c[i + 1];
  rep(i, n - 1) cin >> a[i + 1];

  vector<ll> dp(n, INF);
  ll start = -1;
  for(ll i = n - 1; i >= 0; i--) {
    if(c[i] == 1) {
      start = i;
      break;
    }
  }
  dp[start] = 0;
  for(ll i = start; i >= 1; i--) {
    rep(j, c[i]) {
      ll next  = i - (j + 1);
      dp[next] = min(dp[next], dp[i] + 1);
      if(a[next] == 1) break;
    }
  }
  cout << dp[0] << endl;

  return 0;
}