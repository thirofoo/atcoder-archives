/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/61503694
 * Submitted at: 2025-01-10 00:34:28
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_f
 * Result: WA
 * Execution Time: 51 ms
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

  ll h, w, m;
  cin >> h >> w >> m;
  vector<vector<ll>> syogai(h, vector<ll>{});
  rep(i, m) {
    ll x, y;
    cin >> x >> y;
    x--, y--;
    syogai[x].emplace_back(y);
  }
  ll ans = 0;
  fenwick_tree<ll> fw(w);
  rep(i, w) fw.add(i, 1);

  rep(i, h) {
    if(syogai[i].empty()) {
      ans += w;
      continue;
    }
    sort(syogai[i].begin(), syogai[i].end());
    ans += syogai[i][0];
    for(auto th: syogai[i]) fw.add(th, (fw.sum(th, th + 1) == 0 ? 0 : -1));
    ans += fw.sum(syogai[i][0] + 1, w);
    // cerr << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}