/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67026661
 * Submitted at: 2025-06-23 21:47:07
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bb
 * Result: AC
 * Execution Time: 45 ms
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

  // 別解 : 完全グラフ & コストが同じグラフを超頂点で辺数削減
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> graph(n + m);
  rep(i, m) {
    ll k;
    cin >> k;
    rep(j, k) {
      ll r;
      cin >> r;
      r--;
      graph[r].emplace_back(n + i);
      graph[n + i].emplace_back(r);
    }
  }
  queue<ll> q;
  vector<ll> dist(n + m, INF);
  dist[0] = 0;
  q.push(0);
  while(!q.empty()) {
    ll v = q.front();
    q.pop();
    for(ll u: graph[v]) {
      if(dist[u] == INF) {
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
  rep(i, n) cout << (dist[i] == INF ? -1 : dist[i] / 2) << "\n";

  return 0;
}