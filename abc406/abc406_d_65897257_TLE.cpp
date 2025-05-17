/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65897257
 * Submitted at: 2025-05-17 21:47:16
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_d
 * Result: TLE
 * Execution Time: 2763 ms
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

  ll h, w, n;
  cin >> h >> w >> n;
  vector<vector<ll>> yoko(h), tate(w);
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    yoko[x].emplace_back(y);
    tate[y].emplace_back(x);
  }
  ll q;
  cin >> q;
  using P = pair<ll, ll>;
  set<P> already;
  vector<ll> yoko_minus(h, 0), tate_minus(w, 0);
  while(q--) {
    ll t, v;
    cin >> t >> v;
    v--;
    if(t == 1) {
      cout << yoko[v].size() - yoko_minus[v] << endl;
      for(auto y: yoko[v]) {
        if(already.find(P(v, y)) != already.end()) continue;
        yoko_minus[v]++;
        tate_minus[y]++;
        already.insert(P(v, y));
      }
    } else {
      cout << tate[v].size() - tate_minus[v] << endl;
      for(auto x: tate[v]) {
        if(already.find(P(x, v)) != already.end()) continue;
        yoko_minus[x]++;
        tate_minus[v]++;
        already.insert(P(x, v));
      }
    }
  }

  return 0;
}