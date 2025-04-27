/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65233115
 * Submitted at: 2025-04-27 17:29:59
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_f
 * Result: AC
 * Execution Time: 165 ms
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

  ll n, k;
  cin >> n >> k;
  vector<mint> fact(k + 1, 1), r_fact(k + 1, 1);
  for(int i = 1; i <= k; i++) {
    fact[i]   = fact[i - 1] * i;
    r_fact[i] = (mint) 1 / fact[i];
  }
  auto nCr = [&](ll n_val, ll r_val) -> mint {
    return fact[n_val] * r_fact[r_val] * r_fact[n_val - r_val];
  };
  vector<ll> A(n);
  vector<mint> a(n);
  rep(i, n) {
    cin >> A[i];
    a[i] = A[i];
  }

  // dp[i][j][k] i番目まで見て、j個の仕切りを置き、k個シールを貼った時のシールの貼り方
  vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(3, vector<mint>(k + 1, 0)));
  dp[0][0][0] = 1;
  rep(i, n) rep(j, 3) rep(l, k + 1) {
    if(j != 2) dp[i][j + 1][l] += dp[i][j][l]; // 仕切りを置く
    dp[i + 1][j][l] += dp[i][j][l];            // 仕切りを置かない + シールを貼らない
    if(j == 1) {
      for(ll p = 1; l + p <= k; p++) {
        dp[i + 1][j][l + p] += dp[i][j][l] * nCr(k - l, p) * a[i].pow(p);
      }
    }
  }
  // rep(i, n + 1) {
  //   rep(j, 3) {
  //     rep(l, k + 1) cerr << dp[n][j][l].val() << " ";
  //     cerr << endl;
  //   }
  //   cerr << endl;
  // }
  cout << (dp[n][0][k] + dp[n][1][k] + dp[n][2][k]).val() << endl;

  return 0;
}