/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63281456
 * Submitted at: 2025-03-01 21:48:49
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_e
 * Result: TLE
 * Execution Time: 2214 ms
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

  ll n, m, x;
  cin >> n >> m >> x;
  using P = pair<ll, ll>;
  vector<vector<P>> graph(n * 2, vector<P>{});
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(P(b, 1));
    graph[b + n].emplace_back(P(a + n, 1));
    graph[a].emplace_back(P(a + n, x));
    graph[a + n].emplace_back(P(a, x));
    graph[b].emplace_back(P(b + n, x));
    graph[b + n].emplace_back(P(b, x));
  }
  vector<ll> dist(n * 2, INF);
  dist[0] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0, 0});

  while(!q.empty()) {
    auto [v, d] = q.top();
    q.pop();
    for(auto [nv, nd]: graph[v]) {
      if(dist[nv] > dist[v] + nd) {
        dist[nv] = dist[v] + nd;
        q.push({nv, dist[nv]});
      }
    }
  }
  cout << min(dist[n - 1], dist[n * 2 - 1]) << '\n';

  return 0;
}