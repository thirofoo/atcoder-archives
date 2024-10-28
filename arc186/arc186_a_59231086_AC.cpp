/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc186/submissions/59231086
 * Submitted at: 2024-10-28 20:02:59
 * Problem URL: https://atcoder.jp/contests/arc186/tasks/arc186_a
 * Result: AC
 * Execution Time: 73 ms
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
#define reps(i, n, m) for(ll i = n; i < m; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector dp(n + 1, vector(n + 1, vector(n * n + 1, false)));
  // dp[i][j][k] := (i, j) まで見た時の未固定マスが k 個に出来るか否か
  dp[0][0][0] = true;
  rep(i, n) rep(j, n) rep(k, n * n + 1) {
    if(!dp[i][j][k]) continue;
    reps(x, 2, n + 1) reps(y, 2, n + 1) {
      if(i + x > n || j + y > n || k + x * y > n * n) continue;
      dp[i + x][j + y][k + x * y] = true;
    }
  }
  vector<bool> ans(n * n + 1, false);
  rep(i, n + 1) rep(j, n + 1) rep(k, n * n + 1) {
    ans[n * n - k] = (ans[n * n - k] || dp[i][j][k]);
  }
  // rep(i, n * n + 1) cerr << ans[i] << ' ';
  // cerr << '\n';
  while(q--) {
    ll k;
    cin >> k;
    cout << (ans[k] ? "Yes" : "No") << '\n';
  }

  return 0;
}