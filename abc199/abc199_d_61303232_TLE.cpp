/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/61303232
 * Submitted at: 2025-01-02 00:00:51
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: TLE
 * Execution Time: 2207 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> graph(n);
  dsu uf(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
    uf.merge(a, b);
  }
  ll ans = 1, cand = 0, vis_cnt = 0;
  vector groups = uf.groups();
  vector<ll> colors(n, -1);

  auto dfs = [&](auto self, ll idx, const vector<int> &group) -> void {
    if(idx == group.size()) {
      cand++;
      return;
    }
    ll c_bit = 0;
    for(auto &&to: graph[group[idx]]) {
      if(colors[to] == -1) continue;
      c_bit |= (1LL << colors[to]);
    }
    vis_cnt++;
    for(auto nc: {0, 1, 2}) {
      if((1LL << nc) & c_bit) continue;
      colors[group[idx]] = nc;
      self(self, idx + 1, group);
      colors[group[idx]] = -1;
    }
    vis_cnt--;
    return;
  };
  rep(i, groups.size()) {
    cand                 = 0;
    colors[groups[i][0]] = 0;
    dfs(dfs, 1, groups[i]);
    ans *= cand * 3;
  }
  cout << ans << endl;

  return 0;
}
