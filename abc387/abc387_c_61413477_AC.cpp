/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61413477
 * Submitted at: 2025-01-05 15:08:39
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_c
 * Result: AC
 * Execution Time: 1 ms
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

ll solve(ll num) {
  vector<ll> digits;
  while(num > 0) {
    digits.emplace_back(num % 10);
    num /= 10;
  }
  reverse(digits.begin(), digits.end());

  vector dp(digits.size() + 1, vector(2, vector<ll>(10, 0)));
  dp[0][0][0] = 1;
  rep(i, digits.size()) rep(j, 2) rep(k, 10) {
    rep(tk, (j ? 10 : digits[i] + 1)) {
      if(k != 0 && tk >= k) continue;
      ll ni = i + 1;
      ll nj = j || (tk < digits[i]);
      ll nk = (k == 0 ? tk : k);
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  ll ans = 0;
  rep(i, 10) ans += dp[digits.size()][0][i] + dp[digits.size()][1][i];
  return ans;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll l, r;
  cin >> l >> r;
  cout << solve(r) - solve(l - 1) << '\n';

  return 0;
}
