/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc454/submissions/75044525
 * Submitted at: 2026-04-18 21:04:23
 * Problem URL: https://atcoder.jp/contests/abc454/tasks/abc454_c
 * Result: AC
 * Execution Time: 82 ms
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
  vector<vector<ll>> g(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  queue<ll> que;
  vector<bool> visited(n, false);
  que.push(0);
  visited[0] = true;
  while(!que.empty()) {
    ll v = que.front();
    que.pop();
    for(ll nv: g[v]) {
      if(visited[nv]) continue;
      visited[nv] = true;
      que.push(nv);
    }
  }
  ll ans = 0;
  rep(i, n) ans += visited[i] ? 1 : 0;
  cout << ans << endl;

  return 0;
}