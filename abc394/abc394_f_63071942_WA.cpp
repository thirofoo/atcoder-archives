/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63071942
 * Submitted at: 2025-02-23 00:25:20
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_f
 * Result: WA
 * Execution Time: 122 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

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
    vector<ll> ele = {0};
    for(ll u: graph[v]) {
      if(u == p) continue;
      ele.emplace_back(f(f, u, v));
    }
    sort(ele.begin(), ele.end(), greater<ll>());
    ll res = (deg[v] >= 4 ? (ele.size() >= 2 ? ele[0] + ele[1] + 1 : ele[0] + 1) : 0);
    ans    = max(ans, res);
    // cerr << "res: " << res << ", v: " << v << ", deg: " << deg[v] << endl;
    return res;
  };
  dfs(dfs, 0, -1);
  cout << (ans == 0 ? -1 : 3 * ans + 2) << endl;

  return 0;
}
