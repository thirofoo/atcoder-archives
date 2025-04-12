/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64802723
 * Submitted at: 2025-04-13 00:19:32
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_f
 * Result: AC
 * Execution Time: 312 ms
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
  ll max_depth1 = *max_element(depth1.begin(), depth1.end());
  ll max_depth2 = *max_element(depth2.begin(), depth2.end());
  ll max_d      = max(max_depth1, max_depth2);
  vector<ll> cnt1(max_depth1 + 1, 0), cnt2(max_depth2 + 1, 0);
  rep(i, n1) cnt1[depth1[i]]++;
  rep(i, n2) cnt2[depth2[i]]++;
  vector<ll> conv = convolution_ll(cnt1, cnt2);
  ll ans          = 0;
  rep(i, conv.size()) ans += max(i + 1, max_d) * conv[i];
  cout << ans << endl;

  return 0;
}
