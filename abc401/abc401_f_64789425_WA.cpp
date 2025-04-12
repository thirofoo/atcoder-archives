/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64789425
 * Submitted at: 2025-04-12 22:32:14
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_f
 * Result: WA
 * Execution Time: 271 ms
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
#define rep(i, n) for(auto i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n1;
  cin >> n1;
  vector<vector<ll>> g1(n1);
  for(auto i = 0; i < n1 - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g1[u].push_back(v);
    g1[v].push_back(u);
  }

  ll n2;
  cin >> n2;
  vector<vector<ll>> g2(n2);
  for(auto i = 0; i < n2 - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g2[u].push_back(v);
    g2[v].push_back(u);
  }

  auto dfs_dp = [&](const vector<vector<ll>> &g) -> vector<ll> {
    ll n = g.size();
    vector<ll> dp(n, 0), ans(n, 0);
    auto dfs1 = [&](auto self, ll v, ll p) -> void {
      dp[v] = 0;
      for(auto u: g[v]) {
        if(u == p) continue;
        self(self, u, v);
        dp[v] = max(dp[v], dp[u] + 1);
      }
    };
    dfs1(dfs1, 0, -1);

    auto dfs2 = [&](auto self, ll v, ll p, ll up) -> void {
      ans[v]  = max(dp[v], up);
      ll best = -1, second = -1;
      int bestCount = 0;
      for(auto u: g[v]) {
        if(u == p) continue;
        ll cand = dp[u] + 1;
        if(cand > best) {
          second    = best;
          best      = cand;
          bestCount = 1;
        } else if(cand == best) {
          bestCount++;
        } else if(cand > second) {
          second = cand;
        }
      }
      for(auto u: g[v]) {
        if(u == p) continue;
        ll cand   = dp[u] + 1;
        ll use    = (cand == best && bestCount == 1 ? second : best);
        ll new_up = max(up + 1, use + 1);
        self(self, u, v, new_up);
      }
    };
    dfs2(dfs2, 0, -1, 0);
    return ans;
  };

  vector<ll> dp1 = dfs_dp(g1);
  vector<ll> dp2 = dfs_dp(g2);

  // for(auto x : dp1) cerr << x << " ";
  // cerr << "\n";
  // for(auto x : dp2) cerr << x << " ";
  // cerr << "\n";

  ll ans = 0;
  for(auto x: dp1) ans += x * n2;
  for(auto x: dp2) ans += x * n1;
  ans += n1 * n2;
  cout << ans << "\n";

  return 0;
}
