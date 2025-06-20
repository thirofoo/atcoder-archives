/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66898926
 * Submitted at: 2025-06-20 17:11:09
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_e
 * Result: AC
 * Execution Time: 85 ms
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

  ll n, q;
  cin >> n >> q;
  vector<vector<ll>> eles(n);
  dsu uf(n);
  rep(i, n) eles[i].emplace_back(i + 1);

  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll u, v;
      cin >> u >> v;
      u--, v--;
      if(uf.same(u, v)) continue;
      vector<ll> sum_eles;
      for(auto e: eles[uf.leader(u)]) sum_eles.emplace_back(e);
      for(auto e: eles[uf.leader(v)]) sum_eles.emplace_back(e);
      sort(sum_eles.begin(), sum_eles.end());
      reverse(sum_eles.begin(), sum_eles.end());
      uf.merge(u, v);
      eles[uf.leader(u)].clear();
      rep(i, min(10LL, ll(sum_eles.size()))) {
        eles[uf.leader(u)].emplace_back(sum_eles[i]);
        // cerr << "ele[" << uf.leader(u) << "][" << i << "] = " << sum_eles[i] << "\n";
      }
      // cerr << endl;
    } else {
      ll v, k;
      cin >> v >> k;
      v--, k--;
      cout << (eles[uf.leader(v)].size() > k ? eles[uf.leader(v)][k] : -1) << "\n";
    }
  }

  return 0;
}