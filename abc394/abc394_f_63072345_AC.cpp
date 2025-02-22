/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63072345
 * Submitted at: 2025-02-23 00:38:32
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_f
 * Result: AC
 * Execution Time: 100 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<vector<ll>> graph(n);
  vector<ll> deg(n, 0);
  rep(i, n - 1) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    deg[a]++, deg[b]++;
  }

  ll ans   = 0;
  auto dfs = [&](auto &&f, ll v, ll p) -> ll {
    vector<ll> ele = {0, 0, 0, 0};
    for(ll u: graph[v]) {
      if(u == p) continue;
      ele.emplace_back(f(f, u, v));
    }
    sort(ele.begin(), ele.end(), greater<ll>());
    ll res = 0;
    if(deg[v] >= 4) {
      res = ele[0] + ele[1] + ele[2] + 1;
      ans = max(ans, ele[0] + ele[1] + ele[2] + ele[3] + 1);
    }
    // cerr << "res: " << res << ", v: " << v << ", deg: " << deg[v] << endl;
    return res;
  };
  dfs(dfs, 0, -1);
  cout << (ans == 0 ? -1 : 3 * ans + 2) << endl;

  return 0;
}
