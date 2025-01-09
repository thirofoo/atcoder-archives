/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/61503767
 * Submitted at: 2025-01-10 00:40:22
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_f
 * Result: WA
 * Execution Time: 61 ms
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
  sort(syogai[0].begin(), syogai[0].end());
  rep(i, (syogai[0].empty() ? w : syogai[0][0])) fw.add(i, 1);

  bool flag = false;
  rep(i, h) {
    if(syogai[i].empty()) {
      ans += w;
      continue;
    }
    sort(syogai[i].begin(), syogai[i].end());
    if(syogai[i][0] == 0) flag = true;
    if(!flag) ans += syogai[i][0];
    for(auto th: syogai[i]) fw.add(th, (fw.sum(th, th + 1) == 0 ? 0 : -1));
    ans += fw.sum(syogai[i][0] + 1, w);
    // cerr << ans << '\n';
  }
  cout << ans << '\n';

  return 0;
}