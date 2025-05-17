/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65912864
 * Submitted at: 2025-05-17 22:16:44
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_e
 * Result: AC
 * Execution Time: 82 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    // 桁 DP
    // dp[i][j][k] := i bit 目まで見て未満 flag j, popcnt = k の場合の数
    ll dig = 0, tmp = n;
    while(tmp) {
      tmp /= 2;
      dig++;
    }

    mint ans = 0;
    rep(necc, dig) {
      vector<vector<vector<mint>>> dp(dig + 1, vector<vector<mint>>(2, vector<mint>(k + 1, 0)));
      dp[0][0][0] = 1;
      rep(i, dig) {
        rep(j, 2) {
          rep(l, k + 1) {
            if(dp[i][j][l] == 0) continue;
            rep(b, 2) {
              if(j == 0 && b > ((n >> (dig - i - 1)) & 1)) continue;
              if(i == necc && b == 0) continue;
              ll ni = i + 1;
              ll nj = j | (b < ((n >> (dig - i - 1)) & 1));
              ll nl = l + b;
              if(nl > k) continue;
              dp[ni][nj][nl] += dp[i][j][l];
            }
          }
        }
      }
      ans += (dp[dig][0][k] + dp[dig][1][k]) * mint(2).pow(dig - necc - 1);
    }
    cout << ans.val() << endl;
  }

  return 0;
}