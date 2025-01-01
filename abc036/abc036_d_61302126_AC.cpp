/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc036/submissions/61302126
 * Submitted at: 2025-01-01 23:11:36
 * Problem URL: https://atcoder.jp/contests/abc036/tasks/abc036_d
 * Result: AC
 * Execution Time: 33 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
using ll   = long long;
using ull  = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> graph(n);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector dp(n, vector<mint>(2, 1));
  // dp[i][j] : j == 0 ? 白 : 黒
  auto dfs = [&](auto self, ll now, ll pre) -> void {
    for(auto to: graph[now]) {
      if(to == pre) continue;
      self(self, to, now);
      dp[now][0] *= (dp[to][0] + dp[to][1]);
      dp[now][1] *= dp[to][0];
    }
    return;
  };
  dfs(dfs, 0, -1);
  cout << (dp[0][0] + dp[0][1]).val() << endl;

  return 0;
}