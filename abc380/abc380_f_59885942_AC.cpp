/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc380/submissions/59885942
 * Submitted at: 2024-11-17 01:16:05
 * Problem URL: https://atcoder.jp/contests/abc380/tasks/abc380_f
 * Result: AC
 * Execution Time: 78 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  // Aoki or Takahashi ではなく、先手 or 後手で考えないと NG
  ll n, m, l, total;
  cin >> n >> m >> l;
  total = n + m + l;
  vector<ll> card(total);
  ll aoki = 0, takahashi = 0, sp = 0;
  rep(i, total) {
    cin >> card[i];
    if(i < n) takahashi |= (1LL << i);
    else if(i < n + m) aoki |= (1LL << i);
    else sp |= (1LL << i);
  }

  using T = tuple<ll, ll, ll>;
  map<T, bool> dp;
  auto dfs = [&](auto self, ll first, ll second, ll p) -> bool {
    if(dp.count({first, second, p})) return dp[{first, second, p}];
    rep(i, total) {
      if(!((1LL << i) & first)) continue;
      ll nf = first ^ (1LL << i);
      ll np = p ^ (1LL << i);
      if(!self(self, second, nf, np)) {
        return dp[{first, second, p}] = true;
      }
      rep(j, total) {
        if(!((1LL << j) & p) || card[i] <= card[j]) continue;
        if(!self(self, second, nf ^ (1LL << j), np ^ (1LL << j))) {
          return dp[{first, second, p}] = true;
        }
      }
    }
    return dp[{first, second, p}] = false;
  };
  cout << (dfs(dfs, takahashi, aoki, sp) ? "Takahashi" : "Aoki") << endl;

  return 0;
}