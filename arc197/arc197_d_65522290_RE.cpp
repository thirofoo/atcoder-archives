/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc197/submissions/65522290
 * Submitted at: 2025-05-05 13:05:19
 * Problem URL: https://atcoder.jp/contests/arc197/tasks/arc197_d
 * Result: RE
 * Execution Time: 2402 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<mint> kaizyo(500, 0);
  kaizyo[0] = 1;
  for(ll i = 1; i < 500; i++) kaizyo[i] = kaizyo[i - 1] * i;
  kaizyo[0] = 0;

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    bool ok = true;
    rep(i, n) ok &= (a[i][i] == 1 && a[i][0] == 1 && a[0][i] == 1);
    if(!ok) {
      cout << 0 << '\n';
      continue;
    }

    auto calc = [&](auto self, const vector<int> &group) -> mint {
      mint res = 1;
      vector<ll> deg(n, 0);
      ll size = group.size();
      rep(i, size) rep(j, size) {
        if(a[group[i]][group[j]] == 1) {
          deg[group[i]]++;
          deg[group[j]]++;
        }
      }
      ll cnt = 0;
      rep(i, size) if(deg[group[i]] == size * 2) cnt++;
      res *= kaizyo[cnt];

      dsu uf(n);
      rep(i, size) {
        if(deg[group[i]] == size * 2) continue;
        rep(j, size) {
          if(deg[group[j]] == size * 2 || a[group[i]][group[j]] == 0) continue;
          uf.merge(group[i], group[j]);
        }
      }
      vector<vector<int>> new_group = uf.groups();
      for(auto &g: new_group) {
        if(g.size() == 1) continue;
        res *= self(self, g);
      }
      return res;
    };

    dsu nuf(n);
    rep(i, n) rep(j, n) if(i != 0 && j != 0 && a[i][j] == 1) nuf.merge(i, j);
    vector<vector<int>> group = nuf.groups();
    mint ans                  = 1;
    for(auto &g: group) {
      if(g.size() == 1) continue;
      ans *= calc(calc, g);
    }
    cout << ans.val() << '\n';
  }

  return 0;
}