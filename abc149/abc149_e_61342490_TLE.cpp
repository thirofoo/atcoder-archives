/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc149/submissions/61342490
 * Submitted at: 2025-01-03 22:21:43
 * Problem URL: https://atcoder.jp/contests/abc149/tasks/abc149_e
 * Result: TLE
 * Execution Time: 2233 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  ll threshold, cand = 0, vis_cnt = 0;
  map<ll, ll> mp;
  auto dfs = [&](auto self, ll lh, ll rh) -> void {
    if(a[lh] + a[rh] < threshold || vis_cnt >= m || mp[lh * 1e9 + rh] >= 1) return;
    cand += a[lh] + a[rh];
    vis_cnt++;
    mp[lh * 1e9 + rh]++;
    if(lh != n - 1 && a[lh + 1] + a[rh] >= threshold) self(self, lh + 1, rh);
    if(rh != n - 1 && a[lh] + a[rh + 1] >= threshold) self(self, lh, rh + 1);
    return;
  };

  ll ans  = 0;
  ll left = 0, right = INF;
  while(right - left > 1) {
    threshold = (right + left) / 2;
    cand      = 0;
    vis_cnt   = 0;
    mp        = map<ll, ll>();
    dfs(dfs, 0, 0);
    ans = max(ans, cand);
    if(vis_cnt >= m) left = threshold;
    else right = threshold;
  }
  cout << ans << endl;

  return 0;
}