/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc129/submissions/58876343
 * Submitted at: 2024-10-17 15:51:34
 * Problem URL: https://atcoder.jp/contests/abc129/tasks/abc129_d
 * Result: AC
 * Execution Time: 263 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<ll>> row(h), col(w);
  rep(i, h) rep(j, w) {
    if(s[i][j] == '.') continue;
    row[i].emplace_back(j);
    col[j].emplace_back(i);
  }
  rep(i, h) {
    row[i].emplace_back(-1);
    row[i].emplace_back(w);
    sort(row[i].begin(), row[i].end());
  }
  rep(i, w) {
    col[i].emplace_back(-1);
    col[i].emplace_back(h);
    sort(col[i].begin(), col[i].end());
  }
  ll ans = 0;
  rep(i, h) rep(j, w) {
    if(s[i][j] == '#') continue;
    auto itr1 = lower_bound(row[i].begin(), row[i].end(), j);
    ll x1 = *itr1, x2 = *(itr1 - 1);
    auto itr2 = lower_bound(col[j].begin(), col[j].end(), i);
    ll y1 = *itr2, y2 = *(itr2 - 1);
    ans = max(ans, (x1 - x2 - 1) + (y1 - y2 - 1) - 1);
  }
  cout << ans << '\n';

  return 0;
}
