/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65146633
 * Submitted at: 2025-04-23 23:10:59
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_e
 * Result: WA
 * Execution Time: 87 ms
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

  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> graph(n * k);
  rep(i, n * k - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  bool ans = true;
  auto dfs = [&](auto&& self, ll v, ll p) -> ll {
    ll now = 1, cnt = 0;
    for(auto nv: graph[v]) {
      if(nv == p) continue;
      ll tmp = self(self, nv, v);
      if(tmp == 0) continue;
      cnt++;
      now += tmp;
    }
    if(cnt >= 3 || (cnt == 2 && now > k)) ans = false;
    return now % k;
  };
  dfs(dfs, 0, -1);
  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}