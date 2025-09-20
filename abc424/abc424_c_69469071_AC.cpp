/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69469071
 * Submitted at: 2025-09-20 21:11:56
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_c
 * Result: AC
 * Execution Time: 80 ms
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
  vector<ll> a(n), b(n);
  vector<vector<ll>> graph(n);
  queue<ll> que;
  rep(i, n) {
    cin >> a[i] >> b[i];
    if(a[i] == 0 && b[i] == 0) {
      que.push(i);
      continue;
    }
    a[i]--, b[i]--;
    graph[a[i]].emplace_back(i);
    graph[b[i]].emplace_back(i);
  }
  vector<bool> visited(n, false);
  while(!que.empty()) {
    ll v = que.front();
    que.pop();
    if(visited[v]) continue;
    visited[v] = true;
    for(auto nv: graph[v]) {
      if(visited[nv]) continue;
      que.push(nv);
    }
  }
  ll ans = 0;
  rep(i, n) if(visited[i]) ans++;
  cout << ans << "\n";

  return 0;
}