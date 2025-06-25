/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67059641
 * Submitted at: 2025-06-25 17:08:13
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bj
 * Result: AC
 * Execution Time: 74 ms
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
  vector<ll> a(n), b(n), start;
  vector<vector<ll>> g(n);
  vector<bool> used(n, false);
  rep(i, n) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    if(a[i] == i || b[i] == i) {
      start.emplace_back(i);
      used[i] = true;
    }
    g[a[i]].emplace_back(i);
    g[b[i]].emplace_back(i);
  }

  scc_graph graph(n);
  while(true) {
    vector<ll> new_start;
    for(ll i: start) {
      for(auto j: g[i]) {
        if(!used[j]) {
          new_start.emplace_back(j);
          used[j] = true;
          graph.add_edge(j, i);
        }
      }
    }
    if(new_start.empty()) break;
    swap(start, new_start);
  }

  ll used_cnt = 0;
  rep(i, n) used_cnt += used[i];
  auto scc = graph.scc();
  if(scc.size() != n || used_cnt != n) {
    cout << -1 << "\n";
    return 0;
  }
  rep(i, n) cout << scc[i][0] + 1 << "\n";

  return 0;
}
