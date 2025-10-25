/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70443041
 * Submitted at: 2025-10-25 21:47:03
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_e
 * Result: WA
 * Execution Time: 2209 ms
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
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  string s;
  cin >> s;

  using P = pair<ll, ll>;
  queue<P> que;
  vector<ll> dist1(n, INF), dist2(n, INF);
  rep(i, n) {
    if(s[i] == 'D') continue;
    set<ll> visited;
    que.push(P(i, 0));

    while(!que.empty()) {
      auto [v, d] = que.front();
      que.pop();
      if(dist2[v] <= d) continue;
      if(dist1[v] > d) {
        dist2[v] = dist1[v];
        dist1[v] = d;
      } else dist2[v] = d;
      visited.insert(v);

      for(auto nv: graph[v]) {
        if(dist2[nv] <= d || visited.count(nv)) continue;
        que.push(P(nv, d + 1));
      }
    }
  }
  // rep(i, n) cerr << "i: " << i << ", dist1: " << dist1[i] << ", dist2: " << dist2[i] << '\n';

  rep(i, n) {
    if(s[i] == 'S') continue;
    cout << dist1[i] + dist2[i] << '\n';
  }

  return 0;
}