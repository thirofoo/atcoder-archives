/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58691601
 * Submitted at: 2024-10-12 21:23:25
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_e
 * Result: AC
 * Execution Time: 137 ms
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
  vector<ll> a(n), b(n);
  ll sum = 0;
  rep(i, n) {
    cin >> a[i] >> b[i];
    a[i]--;
    sum += b[i];
  }
  if(sum % 3 != 0) {
    cout << -1 << '\n';
    return 0;
  }

  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(505, vector<ll>(505, INF)));
  // dp[i][j][k] := i人目までみて、Aチーム, Bチームの強さ総和がj, kのときの最小コスト
  dp[0][0][0] = 0;
  rep(i, n) {
    rep(j, 505) {
      rep(k, 505) {
        if(dp[i][j][k] == INF) continue;
        rep(l, 3) {
          if(l == 0) {
            ll nj            = min(j + b[i], 504LL);
            dp[i + 1][nj][k] = min(dp[i + 1][nj][k], dp[i][j][k] + (a[i] != l));
          } else if(l == 1) {
            ll nk            = min(k + b[i], 504LL);
            dp[i + 1][j][nk] = min(dp[i + 1][j][nk], dp[i][j][k] + (a[i] != l));
          } else {
            dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + (a[i] != l));
          }
        }
      }
    }
  }
  ll ans = dp[n][sum / 3][sum / 3];
  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}