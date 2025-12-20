/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71860469
 * Submitted at: 2025-12-20 21:51:38
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_e
 * Result: WA
 * Execution Time: 119 ms
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
  rep(i, n + 1) {
    sort(graph[i].begin(), graph[i].end());
    // rep(j, graph[i].size()) {
    //   cerr << graph[i][j].second << " ";
    // }
    // cerr << "\n";
  }

  auto dfs = [&](auto &&self, ll now) -> void {
    ll idx = 0, start, num;
    while(idx < graph[now].size()) {
      num   = graph[now][idx].first;
      start = idx;
      while(idx < graph[now].size() && graph[now][idx].first == num) {
        cout << graph[now][idx].second << " ";
        idx++;
      }
      for(ll i = start; i < idx; i++) {
        self(self, graph[now][i].second);
      }
    }
  };
  dfs(dfs, 0);
  cout << "\n";

  return 0;
}