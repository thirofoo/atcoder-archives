/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/61303777
 * Submitted at: 2025-01-02 00:35:57
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: AC
 * Execution Time: 10 ms
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

  // ※ uf.groups() を使ってやるのは NG (pre-order 等の順番でやらないと NG)
  // ※ そうしないと 3 * 2^(N-1) でなく、意図的に 3^N に近いケースが作れる

  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> graph(n);
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  ll ans = 1, cand = 0, vis_cnt = 0;
  vector<ll> colors(n, -1);

  vector<ll> group;
  vector<bool> seen(n, false);
  auto dfs1 = [&](auto self, ll now, ll pre) -> void {
    group.emplace_back(now);
    seen[now] = true;
    for(auto to: graph[now]) {
      if(seen[to]) continue;
      self(self, to, now);
    }
    return;
  };

  auto dfs2 = [&](auto self, ll idx) -> void {
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
    rep(nc, 3) {
      if((1LL << nc) & c_bit) continue;
      colors[group[idx]] = nc;
      self(self, idx + 1);
      colors[group[idx]] = -1;
    }
    vis_cnt--;
    return;
  };

  rep(i, n) {
    if(seen[i]) continue;
    group.clear();
    dfs1(dfs1, i, -1);

    cand = 0;
    dfs2(dfs2, 0);
    ans *= cand;
  }
  cout << ans << endl;

  return 0;
}