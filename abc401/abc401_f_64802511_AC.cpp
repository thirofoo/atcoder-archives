/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64802511
 * Submitted at: 2025-04-13 00:13:52
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_f
 * Result: AC
 * Execution Time: 201 ms
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

  ll n1;
  cin >> n1;
  vector<vector<ll>> g1(n1);
  rep(i, n1 - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g1[u].emplace_back(v);
    g1[v].emplace_back(u);
  }
  ll n2;
  cin >> n2;
  vector<vector<ll>> g2(n2);
  rep(i, n2 - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g2[u].emplace_back(v);
    g2[v].emplace_back(u);
  }
  auto calc_depth = [&](vector<vector<ll>>& g) -> vector<ll> {
    ll n = g.size();
    vector<ll> d(n, 0), res(n, -1);
    auto dfs = [&](auto&& self, ll v, ll prev, vector<ll>& depth) -> void {
      for(auto nv: g[v]) {
        if(nv == prev) continue;
        depth[nv] = depth[v] + 1;
        self(self, nv, v, depth);
      }
    };
    dfs(dfs, 0, -1, d);
    ll max_depth1 = -1, max_idx1 = -1;
    for(ll i = 0; i < n; i++) {
      if(max_depth1 < d[i]) {
        max_depth1 = d[i];
        max_idx1   = i;
      }
    }
    vector<ll> d1(n, 0);
    dfs(dfs, max_idx1, -1, d1);
    ll max_depth2 = -1, max_idx2 = -1;
    for(ll i = 0; i < n; i++) {
      if(max_depth2 < d1[i]) {
        max_depth2 = d1[i];
        max_idx2   = i;
      }
    }
    vector<ll> d2(n, 0);
    dfs(dfs, max_idx2, -1, d2);
    rep(i, n) res[i] = max(d1[i], d2[i]);
    return res;
  };

  vector<ll> depth1 = calc_depth(g1), depth2 = calc_depth(g2);
  sort(depth2.begin(), depth2.end());
  vector<ll> rui(n2 + 1, 0);
  rep(i, n2) rui[i + 1] = rui[i] + depth2[i];
  ll max_len            = max(*max_element(depth1.begin(), depth1.end()), *max_element(depth2.begin(), depth2.end()));

  ll ans = 0;
  rep(i, n1) {
    ll idx = lower_bound(depth2.begin(), depth2.end(), max_len - depth1[i]) - depth2.begin();
    ans += (rui[n2] - rui[idx]) + (depth1[i] + 1) * (n2 - idx);
    ans += idx * max_len;
  }
  cout << ans << endl;

  return 0;
}
