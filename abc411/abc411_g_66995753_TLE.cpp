/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66995753
 * Submitted at: 2025-06-22 15:19:58
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_g
 * Result: TLE
 * Execution Time: 6631 ms
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

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> cnt(n, vector<ll>(n, 0));
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    cnt[u][v]++;
    cnt[v][u]++;
  }
  vector<vector<mint>> dp;
  mint ans = 0;
  rep(i, n) for(ll j = i + 1; j < n; j++) ans += cnt[i][j] * (cnt[i][j] - 1) / 2;
  rep(start, n) {
    dp.assign((1LL << n), vector<mint>(n, 0));
    dp[1 << start][start] = 1;
    rep(bit, (1LL << n)) rep(cur, n) rep(next, n) {
      if(cnt[cur][next] == 0) continue;
      if(next == start && (bit & (1LL << start)) != 0 && __builtin_popcountll(bit) != 2) {
        ans += dp[bit][cur] * cnt[cur][next] / mint(__builtin_popcountll(bit)) / 2;
      }
      if((bit & (1LL << next)) == 0) {
        dp[bit | (1LL << next)][next] += dp[bit][cur] * cnt[cur][next];
      }
    }
    // cerr << "ans: " << ans.val() << endl;
  }
  cout << ans.val() << endl;

  return 0;
}