/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71865709
 * Submitted at: 2025-12-20 22:05:16
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_e
 * Result: RE
 * Execution Time: 179 ms
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

  ll n;
  cin >> n;
  using P = pair<ll, ll>;
  vector<vector<P>> graph(n + 1);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    graph[x].emplace_back(P(y, i + 1));
  }
  rep(i, n + 1) sort(graph[i].begin(), graph[i].end());

  auto dfs = [&](auto &&self, ll now) -> void {
    ll idx = 0, start, num;
    while(idx < graph[now].size()) {
      num   = graph[now][idx].first;
      start = idx;
      while(idx < graph[now].size() && graph[now][idx].first == num) {
        cout << graph[now][idx].second << " ";
        idx++;
      }
      for(ll i = start + 1; i < idx; i++) {
        for(auto pr: graph[graph[now][i].second]) {
          graph[graph[now][start].second].emplace_back(pr);
        }
      }
      sort(graph[start].begin(), graph[start].end());
      self(self, graph[now][start].second);
    }
  };
  dfs(dfs, 0);
  cout << "\n";

  return 0;
}