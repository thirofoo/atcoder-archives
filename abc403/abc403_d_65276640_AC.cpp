/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65276640
 * Submitted at: 2025-04-27 22:05:58
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_d
 * Result: AC
 * Execution Time: 31 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, d;
  cin >> n >> d;
  vector<ll> counts(1000001, 0);
  ll max_val = 0;
  for(ll i = 0; i < n; ++i) {
    ll val;
    cin >> val;
    counts[val]++;
    if(val > max_val) max_val = val;
  }

  if(d == 0) {
    ll deleted_count = 0;
    for(ll count: counts) {
      deleted_count += max(0LL, count - 1);
    }
    cout << deleted_count << endl;
    return 0;
  }

  ll total_max_kept = 0;
  rep(r, d) {
    vector<pair<ll, ll>> eles;
    for(ll val = r; val <= max_val; val += d) {
      if(counts[val] > 0) eles.push_back({(ll) val, counts[val]});
    }

    if(eles.empty()) {
      continue;
    }

    ll p = eles.size();
    vector<vector<ll>> dp(p, vector<ll>(2, 0));
    // dp[i][j] : i 番目までみて直近のものを選んだか否か j の時の最小削除数 ??
    dp[0][0] = 0;
    dp[0][1] = eles[0].second;

    for(ll k = 1; k < p; ++k) {
      auto [cur_val, cur_cnt] = eles[k];
      ll prev_val             = eles[k - 1].first;

      dp[k][0] = max(dp[k - 1][0], dp[k - 1][1]);
      if((ll) cur_val - prev_val == d) {
        dp[k][1] = dp[k - 1][0] + cur_cnt;
      } else {
        dp[k][1] = max(dp[k - 1][0], dp[k - 1][1]) + cur_cnt;
      }
    }
    total_max_kept += max(dp[p - 1][0], dp[p - 1][1]);
  }
  cout << n - total_max_kept << endl;

  return 0;
}