/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61403960
 * Submitted at: 2025-01-05 01:16:39
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_f
 * Result: AC
 * Execution Time: 54 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;
using ull  = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  scc_graph g(n);
  using P = pair<ll, ll>;
  vector<P> edges;
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    g.add_edge(i, a[i]);
    edges.emplace_back(i, a[i]);
  }
  vector<vector<int>> s = g.scc();
  vector<ll> group(n, -1);
  rep(i, s.size()) for(auto j: s[i]) group[j] = i;

  vector<vector<ll>> graph(s.size());
  vector<ll> in(s.size(), 0);
  for(auto [u, v]: edges) {
    if(group[u] == group[v]) continue;
    graph[group[v]].emplace_back(group[u]);
    in[group[u]]++;
  }

  vector dp(s.size(), vector<mint>(m + 1, 0));
  vector<bool> vis(s.size(), false);
  auto dfs = [&](auto self, ll now) -> void {
    vis[now] = true;
    for(ll i = 1; i <= m; i++) {
      dp[now][i] = 1;
      for(auto to: graph[now]) {
        if(!vis[to]) self(self, to);
        dp[now][i] *= dp[to][m] - dp[to][i - 1];
      }
    }
    if(graph[now].empty()) dp[now][1] = 1;
    rep(i, m) dp[now][i + 1] += dp[now][i];
    return;
  };
  rep(i, s.size()) {
    if(vis[i]) continue;
    dfs(dfs, i);
  }
  mint ans = 1;
  rep(i, s.size()) if(in[i] == 0) ans *= dp[i][m];
  cout << ans.val() << '\n';

  return 0;
}
