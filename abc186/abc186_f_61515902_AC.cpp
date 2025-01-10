/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/61515902
 * Submitted at: 2025-01-10 19:37:45
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_f
 * Result: AC
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

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
  rep(i, h) {
    syogai[i].emplace_back(w);
    sort(syogai[i].begin(), syogai[i].end());
  }

  ll ans    = 0;
  bool flag = false;
  fenwick_tree<ll> fw(w + 1);
  rep(i, syogai[0][0]) fw.add(i, 1);
  rep(i, h) {
    flag |= (syogai[i][0] == 0);
    if(!flag) ans += syogai[i][0];
    for(auto th: syogai[i]) fw.add(th, (fw.sum(th, th + 1) == 0 ? 0 : -1));
    ans += fw.sum((flag ? 0 : syogai[i][0] + 1), w + 1);
    // cerr << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}