/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63510367
 * Submitted at: 2025-03-08 21:11:12
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_d
 * Result: AC
 * Execution Time: 101 ms
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
  vector<vector<ll>> graph(n, vector<ll>(n, INF));
  rep(i, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    graph[u][v] = w;
    graph[v][u] = w;
  }

  ll ans = INF;
  for(ll size = 1; size <= n; size++) {
    vector<ll> perm(n);
    iota(perm.begin(), perm.end(), 0);
    do {
      if(perm[0] != 0 || perm[size - 1] != n - 1) continue;
      ll xor_sum = 0;
      bool ok    = true;
      rep(i, size - 1) {
        if(graph[perm[i]][perm[i + 1]] == INF) {
          ok = false;
          break;
        }
        xor_sum ^= graph[perm[i]][perm[i + 1]];
      }
      if(ok) {
        ans = min(ans, xor_sum);
        // cerr << "xor_sum: " << xor_sum << '\n';
      }
    } while(next_permutation(perm.begin(), perm.end()));
  }
  cout << (ans == INF ? -1 : ans) << '\n';

  return 0;
}