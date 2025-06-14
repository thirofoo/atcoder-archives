/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66732839
 * Submitted at: 2025-06-14 21:12:30
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_d
 * Result: WA
 * Execution Time: 14 ms
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
  using P = pair<ll, ll>;
  vector<vector<P>> graph(n);
  rep(i, m) {
    ll a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    graph[a].emplace_back(b, w);
    graph[b].emplace_back(a, w);
  }
  vector<vector<bool>> visited(n, vector<bool>((1LL << 10), false));
  queue<P> q;
  q.emplace(0, 0);
  while(!q.empty()) {
    auto [node, mask] = q.front();
    q.pop();
    if(visited[node][mask]) continue;
    visited[node][mask] = true;
    for(auto [next_node, weight]: graph[node]) {
      ll next_mask = mask ^ weight;
      if(!visited[next_node][next_mask]) {
        q.emplace(next_node, next_mask);
      }
    }
  }
  rep(i, (1LL << 10)) {
    if(visited[n - 1][i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}