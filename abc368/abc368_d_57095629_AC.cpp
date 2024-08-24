/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57095629
 * Submitted at: 2024-08-24 23:04:04
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_d
 * Result: AC
 * Execution Time: 103 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> graph(n, vector<ll>{});
  vector<ll> deg(n, 0);
  for(ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  set<ll> s;
  for(ll i = 0; i < k; i++) {
    ll v;
    cin >> v;
    v--;
    s.insert(v);
  }
  queue<ll> que;
  for(int i = 0; i < n; i++) {
    if(deg[i] == 1 && !s.count(i)) {
      que.push(i);
    }
  }

  ll ans = n;
  vector<bool> erased(n, false);
  while(!que.empty()) {
    ll v = que.front();
    que.pop();
    ans--;
    erased[v] = true;
    for(ll u: graph[v]) {
      if(erased[u]) continue;
      deg[u]--;
      if(deg[u] == 1 && !s.count(u)) {
        que.push(u);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}