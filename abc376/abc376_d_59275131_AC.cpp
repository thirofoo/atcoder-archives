/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc376/submissions/59275131
 * Submitted at: 2024-10-30 19:30:43
 * Problem URL: https://atcoder.jp/contests/abc376/tasks/abc376_d
 * Result: AC
 * Execution Time: 47 ms
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
  vector<vector<ll>> graph(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
  }
  using T = tuple<ll, ll, ll>;
  queue<T> q;
  q.push(T(0, -1, 0));
  vector<bool> visited(n, false);
  while(!q.empty()) {
    auto [v, p, d] = q.front();
    q.pop();
    if(visited[v] && v == 0) {
      cout << d << endl;
      return 0;
    }
    if(visited[v]) continue;
    visited[v] = true;
    for(auto u: graph[v]) {
      if(u == p) continue;
      q.push(T(u, v, d + 1));
    }
  }
  cout << -1 << endl;

  return 0;
}