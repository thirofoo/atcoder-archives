/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc373/submissions/58213329
 * Submitted at: 2024-09-28 21:35:00
 * Problem URL: https://atcoder.jp/contests/abc373/tasks/abc373_d
 * Result: AC
 * Execution Time: 877 ms
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

  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> graph(n);
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    graph[u - 1].emplace_back(v, w);
    graph[v - 1].emplace_back(-u, w);
  }
  vector<ll> ans(n, 0);
  vector<bool> visited(n, false);
  auto dfs = [&](auto &&f, ll now, ll now_num) -> void {
    visited[now] = true;
    cerr << now << " " << now_num << endl;
    for(auto [next, w]: graph[now]) {
      ll to = next;
      if(to < 0) to = -to;
      to--;
      if(visited[to]) continue;
      ans[to] = (next >= 0 ? w + now_num : now_num - w);
      f(f, to, ans[to]);
    }
    return;
  };
  rep(i, n) {
    if(visited[i]) continue;
    dfs(dfs, i, 0);
  }
  rep(i, n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}