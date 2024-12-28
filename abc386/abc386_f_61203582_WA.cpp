/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61203582
 * Submitted at: 2024-12-28 22:39:59
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_f
 * Result: WA
 * Execution Time: 278 ms
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
  vector<vector<ll>> ch_idx_s(26), ch_idx_t(26);
  rep(i, s.size()) ch_idx_s[s[i] - 'a'].emplace_back(i);
  rep(i, t.size()) ch_idx_t[t[i] - 'a'].emplace_back(i);
  vector<vector<ll>> dp(s.size() + 1, vector<ll>(k + 1, INF));
  // dp[i][j] : i 文字目までみて j 回したときの index の最小値
  dp[0][0] = 0;
  rep(i, s.size()) {
    rep(j, k) {
      if(!dp[i][j]) continue;
      // 何もしない時
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      // 削除する時
      dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
      // 次の文字を使う時
      ll next_idx = lower_bound(ch_idx_s[s[i] - 'a'].begin(), ch_idx_s[s[i] - 'a'].end(), dp[i][j]) - ch_idx_s[s[i] - 'a'].begin();
      if(next_idx < ch_idx_s[s[i] - 'a'].size()) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], ch_idx_s[s[i] - 'a'][next_idx] + 1);
    }
  }
  rep(i, s.size() + 1) {
    rep(j, k + 1) {
      if(dp[i][j] != INF && j + (s.size() - i - 1) <= k) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }
  cout << "No" << '\n';

  return 0;
}