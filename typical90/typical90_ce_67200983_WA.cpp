/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67200983
 * Submitted at: 2025-06-30 18:37:32
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ce
 * Result: WA
 * Execution Time: 250 ms
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

  // 解説 AC : 平方分割 (√2M を境に戦略分岐)
  // ※ 字数の総和が 2M なので、その sqrt を境界にすると計算量 O(Q√M) で済む
  ll n, m;
  cin >> n >> m;
  ll threshold = sqrt(2 * m);
  vector<vector<ll>> g1(n), g2(n);
  rep(i, m) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    g1[u].emplace_back(v);
    g1[v].emplace_back(u);
  }
  rep(i, n) for(auto to: g1[i]) {
    if(g1[to].size() <= threshold) continue;
    g2[i].emplace_back(to);
  }

  ll q;
  cin >> q;
  vector<ll> ans(n, 1), t1(n, 0), t2(n, 0), latest(n, 0);
  rep(i, q) {
    ll x, y;
    cin >> x >> y;
    x--;
    ll best_turn = t1[x], best_ans = ans[x];
    for(auto to: g2[x]) {
      if(t2[to] > best_turn) {
        best_turn = t2[to];
        best_ans  = latest[to];
      }
    }
    cout << best_ans << '\n';

    t1[x]     = i;
    t2[x]     = i;
    ans[x]    = y;
    latest[x] = y;
    if(g1[x].size() <= threshold) {
      for(auto to: g1[x]) {
        ans[to] = y;
        t1[to]  = i;
      }
    }
  }

  return 0;
}