/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61413938
 * Submitted at: 2025-01-05 15:25:23
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_c
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll solve(ll num) {
  vector<ll> digits;
  while(num > 0) {
    digits.emplace_back(num % 10);
    num /= 10;
  }
  reverse(digits.begin(), digits.end());
  ll size = digits.size();

  // dp[i][j][k] : i 桁目・j 未満フラグ・k top 項
  vector dp(size, vector(2, vector<ll>(10, 0)));
  for(ll i = 1; i <= digits[0]; i++) dp[0][i < digits[0]][i] = 1;
  for(ll i = 1; i < size; i++) {
    for(ll j = 1; j <= 9; j++) dp[i][1][j] = 1;
  }

  rep(i, size - 1) rep(j, 2) rep(k, 10) {
    rep(nk, (j ? 10 : digits[i + 1] + 1)) {
      if(nk >= k) break;
      ll ni = i + 1;
      ll nj = j || (nk < digits[i + 1]);
      dp[ni][nj][k] += dp[i][j][k];
    }
  }
  ll ans = 0;
  rep(i, 10) ans += dp[size - 1][0][i] + dp[size - 1][1][i];
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
