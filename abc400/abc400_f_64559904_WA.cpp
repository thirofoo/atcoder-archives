/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64559904
 * Submitted at: 2025-04-05 22:40:08
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_f
 * Result: WA
 * Execution Time: 3314 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

ll calc_sum_S(ll l, ll r, ll c, const vector<vector<ll>>& dp, const vector<ll>& c_doubled, ll current_len) {
  ll current_sum = 0;
  ll start       = -1;
  for(ll k = l; k <= r; k++) {
    if(c_doubled[k] != c) {
      if(start == -1) start = k;
    } else {
      if(start != -1) {
        ll sub_l = start, sub_r = k - 1;
        if(sub_l <= sub_r) {
          ll sub_len = sub_r - sub_l + 1;
          if(sub_len < current_len) current_sum = (dp[sub_l][sub_r] == INF ? INF : current_sum + dp[sub_l][sub_r]);
          else return INF;
        }
        start = -1;
      }
    }
  }
  if(start != -1) {
    ll sub_l = start, sub_r = r;
    if(sub_l <= sub_r) {
      ll sub_len = sub_r - sub_l + 1;
      if(sub_len < current_len) current_sum = (dp[sub_l][sub_r] == INF ? INF : current_sum + dp[sub_l][sub_r]);
      else return INF;
    }
  }
  return current_sum;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> c(n), x(n + 1);
  rep(i, n) cin >> c[i];
  rep(i, n) cin >> x[i + 1];

  vector<ll> c_doubled(2 * n);
  rep(i, 2 * n) c_doubled[i] = c[i % n];
  vector<vector<ll>> dp(2 * n, vector<ll>(2 * n, INF));

  for(ll len = 1; len <= n; len++) {
    rep(l, 2 * n) {
      ll r = l + len - 1;
      if(r >= 2 * n) break;
      if(len == 1) {
        ll color = c_doubled[l];
        dp[l][r] = (color >= 1 && color <= n ? 1LL + x[color] : INF);
        continue;
      }
      ll split_cost = INF;
      for(ll k = l; k < r; k++)
        if(k + 1 < 2 * n) split_cost = min(split_cost, dp[l][k] + dp[k + 1][r]);
      dp[l][r]   = split_cost;
      ll overall = INF;
      for(ll c = 1; c <= n; c++) {
        ll sub_cost = calc_sum_S(l, r, c, dp, c_doubled, len);
        if(sub_cost == INF) continue;
        ll t_cost = len + x[c] + sub_cost;
        overall   = min(overall, t_cost);
      }
      dp[l][r] = min(dp[l][r], overall);
    }
  }

  ll ans        = INF;
  rep(i, n) ans = min(ans, dp[i][i + n - 1]);
  cout << ans << "\n";

  return 0;
}
