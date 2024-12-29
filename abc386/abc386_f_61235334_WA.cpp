/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61235334
 * Submitted at: 2024-12-29 23:03:51
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_f
 * Result: WA
 * Execution Time: 157 ms
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

  ll k;
  string s, t;
  cin >> k >> s >> t;
  if(abs((int) s.size() - (int) t.size()) > k) {
    cout << "No" << '\n';
    return 0;
  }
  if(s.size() < t.size()) swap(s, t);
  vector dp(s.size() + 1, vector<ll>(2 * k + 1, INF));
  dp[0][k] = 0;
  // dp[i][j] := s の i 文字目, t の i + j - k 文字目まで見た時の最小操作回数
  rep(i, s.size()) rep(d, 2 * k + 1) {
    ll j = i + d - k;
    if(j < 0 || j >= t.size()) continue;
    // 文字変更遷移
    dp[i + 1][d] = min(dp[i + 1][d], dp[i][d] + (s[i] == t[j] ? 0 : 1));
    // t に文字挿入遷移
    if(d != 2 * k) dp[i][d + 1] = min(dp[i][d + 1], dp[i][d] + 1);
    // s に文字挿入遷移
    if(d != 0) dp[i + 1][d - 1] = min(dp[i + 1][d - 1], dp[i][d] + 1);
  }
  // cerr << dp[s.size()][k - (s.size() - t.size())] << '\n';
  cout << (dp[s.size()][k - (s.size() - t.size())] <= k ? "Yes" : "No") << '\n';

  return 0;
}