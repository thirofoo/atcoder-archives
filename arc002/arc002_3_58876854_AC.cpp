/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc002/submissions/58876854
 * Submitted at: 2024-10-17 16:12:55
 * Problem URL: https://atcoder.jp/contests/arc002/tasks/arc002_3
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

#include <atcoder/all>
using mint = atcoder::modint998244353;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> ch = {'A', 'B', 'X', 'Y'};

  ll ans = INF;
  rep(l1, ch.size()) rep(l2, ch.size()) rep(r1, ch.size()) rep(r2, ch.size()) {
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    rep(i, n) {
      bool flag = false;
      flag |= (i != n - 1 && s[i] == ch[l1] && s[i + 1] == ch[l2]);
      flag |= (i != n - 1 && s[i] == ch[r1] && s[i + 1] == ch[r2]);
      if(flag) dp[i + 2] = min(dp[i + 2], dp[i] + 1);
      else dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }
    ans = min(ans, dp[n]);
  }
  cout << ans << '\n';

  return 0;
}
