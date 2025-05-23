/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/63071444
 * Submitted at: 2025-02-23 00:11:49
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_f
 * Result: RE
 * Execution Time: 132 ms
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
    a--;
    b--;
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
    if(deg[v] >= 4 && ele.size() >= 2) {
      ans = max(ans, 1 + ele[0] + ele[1]);
    }
    ll res = (deg[v] >= 4 ? 1 + ele[0] : 0);
    cerr << "res: " << res << ", v: " << v << endl;
    // return res;
  };
  dfs(dfs, 0, -1);
  cout << (ans == 0 ? -1 : 3 * ans + 2) << endl;

  return 0;
}
