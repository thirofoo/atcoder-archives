/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc182/submissions/56607133
 * Submitted at: 2024-08-11 22:01:10
 * Problem URL: https://atcoder.jp/contests/arc182/tasks/arc182_a
 * Result: AC
 * Execution Time: 22 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll   = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> p(q), v(q);
  rep(i, q) {
    cin >> p[i] >> v[i];
    p[i]--;
  }
  dsu uf(q);
  for(ll i = 0; i < q; i++) {
    bool left = false, right = false;
    for(ll j = 0; j < q; j++) {
      if(i == j) continue;
      if((j < i && v[j] <= v[i]) || (j > i && v[j] >= v[i])) continue;
      left |= (p[j] <= p[i]);
      right |= (p[j] >= p[i]);
      uf.merge(i, j);
    }
    if(left && right) {
      return cout << 0 << '\n', 0;
    }
  }
  vector g = uf.groups();
  mint ans = 1;
  rep(i, g.size()) if(g[i].size() == 1) ans *= 2;
  cout << ans.val() << '\n';

  return 0;
}