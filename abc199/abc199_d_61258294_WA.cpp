/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/61258294
 * Submitted at: 2024-12-31 00:55:37
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: WA
 * Execution Time: 2210 ms
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
  vector groups = uf.groups();
  ll ans        = 1;
  vector<ll> color(n, -1);
  for(auto group: groups) {
    ll cand = 0, cnt = 0;
    set<ll> st;
    auto dfs = [&](auto self, ll now, ll pre, ll situation) -> void {
      for(auto nc: {0, 1, 2}) {
        if(pre != -1 && color[pre] == nc) continue;
        bool ng = false;
        for(auto to: graph[now]) ng |= (nc == color[to]);
        if(ng) continue;
        color[now] = nc;
        cnt++;
        if(cnt == group.size()) st.insert(situation * 3 + nc);
        else {
          for(auto to: graph[now]) {
            if(color[to] != -1) continue;
            self(self, to, now, situation * 3 + nc);
          }
        }
        color[now] = -1;
        cnt--;
      }
      return;
    };
    dfs(dfs, group[0], -1, 0LL);
    ans *= st.size();
  }
  cout << ans << endl;

  return 0;
}