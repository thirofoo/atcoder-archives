/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64804110
 * Submitted at: 2025-04-13 01:07:47
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_g
 * Result: AC
 * Execution Time: 268 ms
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
  using P = pair<ll, ll>;
  vector<P> s, g;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    s.emplace_back(x, y);
  }
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    g.emplace_back(x, y);
  }

  using ld = long double;
  vector<vector<ld>> dist(n, vector<ld>(n));
  rep(i, n) rep(j, n) {
    auto [sx, sy] = s[i];
    auto [gx, gy] = g[j];
    dist[i][j]    = sqrt((ld) (sx - gx) * (sx - gx) + (ld) (sy - gy) * (sy - gy));
  }

  ld left = 0, right = 2e18;
  while(right - left > 1e-7 && (right - left) / right > 1e-7) {
    ld mid = (left + right) / 2;
    // cerr << mid << endl;
    mf_graph<ld> graph(2 * n + 2);
    rep(i, n) {
      graph.add_edge(0, i + 1, 1);
      graph.add_edge(n + 1 + i, 2 * n + 1, 1);
    }
    rep(i, n) rep(j, n) if(dist[i][j] <= mid) graph.add_edge(i + 1, n + 1 + j, 1);
    ll max_flow = graph.flow(0, 2 * n + 1);
    if(max_flow == n) right = mid;
    else left = mid;
  }
  cout << fixed << setprecision(10) << right << endl;

  return 0;
}