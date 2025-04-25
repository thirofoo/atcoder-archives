/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65189664
 * Submitted at: 2025-04-25 19:31:34
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_e
 * Result: WA
 * Execution Time: 13 ms
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
  string s, t;
  cin >> s >> t;
  vector<char> check(26, '?');
  rep(i, n) {
    if(check[s[i] - 'a'] != '?') {
      if(check[s[i] - 'a'] != t[i]) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      check[s[i] - 'a'] = t[i];
    }
  }

  ll ans = 0;
  vector<vector<ll>> graph(26);
  rep(i, 26) {
    if(check[i] != '?' && check[i] != i + 'a') {
      graph[i].emplace_back(check[i] - 'a');
      ans++;
    }
  }
  // 有向グラフにおいて閉路が何個存在するかを調べる
  vector<bool> visited(26, false), in_stack(26, false), on_stack(26, false), in_cycle(26, false);
  auto dfs = [&](auto self, ll v) -> void {
    visited[v]  = true;
    in_stack[v] = true;
    on_stack[v] = true;
    for(auto nv: graph[v]) {
      if(!visited[nv]) {
        self(self, nv);
      } else if(in_stack[nv]) {
        in_cycle[nv] = true;
        ans++;
      }
    }
    in_stack[v] = false;
  };

  rep(i, 26) {
    if(!visited[i] && check[i] != '?') {
      dfs(dfs, i);
    }
  }
  cout << ans << endl;

  return 0;
}