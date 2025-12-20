/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71875854
 * Submitted at: 2025-12-20 22:34:28
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_e
 * Result: AC
 * Execution Time: 151 ms
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
  vector<map<ll, ll>> graph(n + 1);
  vector<ll> convert(n + 1, 0);
  iota(convert.begin(), convert.end(), 0);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if(graph[convert[x]].count(y)) convert[i + 1] = graph[convert[x]][y];
    else graph[convert[x]][y] = i + 1;
  }
  vector<vector<ll>> con_to_idx(n + 1);
  rep(i, n + 1) con_to_idx[convert[i]].emplace_back(i);

  auto dfs = [&](auto &&self, ll now) -> void {
    for(auto [_, to]: graph[now]) {
      for(ll idx: con_to_idx[to]) cout << idx << " ";
      self(self, to);
    }
  };
  dfs(dfs, 0);
  cout << "\n";

  return 0;
}