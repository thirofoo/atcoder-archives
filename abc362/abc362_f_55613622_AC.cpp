/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55613622
 * Submitted at: 2024-07-14 22:38:42
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_f
 * Result: AC
 * Execution Time: 598 ms
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
  vector<vector<ll>> Graph(n);
  rep(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    Graph[u].emplace_back(v);
    Graph[v].emplace_back(u);
  }

  vector<ll> partial_num(n, 0);
  auto dfs1 = [&](auto self, ll now, ll pre) -> void {
    for(auto next: Graph[now]) {
      if(next == pre) continue;
      self(self, next, now);
      partial_num[now] += partial_num[next];
    }
    partial_num[now]++;
  };
  dfs1(dfs1, 0, -1);

  ll now = 0, parent = -1;
  while(true) {
    ll max_child = -1, child_num = -1;
    for(auto next: Graph[now]) {
      if(next == parent) continue;
      if(partial_num[next] > child_num) {
        child_num = partial_num[next];
        max_child = next;
      }
    }
    if(child_num * 2 <= n) break;
    parent = now;
    now    = max_child;
  }
  ll center = now;

  // now が重心 ⇒ 重心から全方位に言って emplace_back
  vector<ll> ans;
  queue<pair<ll, ll>> que;
  for(auto start: Graph[center]) {
    que.push(pair(start, center));
    while(!que.empty()) {
      auto [here, par] = que.front();
      que.pop();
      ans.emplace_back(here);
      for(auto next: Graph[here]) {
        if(next == par) continue;
        que.push(pair(next, here));
      }
    }
  }
  ans.emplace_back(center);
  rep(i, n) cerr << ans[i] + 1 << " \n"[i == n - 1];
  rep(i, n / 2) cout << ans[i] + 1 << " " << ans[i + n / 2] + 1 << endl;

  return 0;
}