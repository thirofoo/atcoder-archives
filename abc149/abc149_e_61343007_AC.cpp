/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc149/submissions/61343007
 * Submitted at: 2025-01-03 22:41:33
 * Problem URL: https://atcoder.jp/contests/abc149/tasks/abc149_e
 * Result: AC
 * Execution Time: 137 ms
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
  vector<ll> a(n, 0), rui(n + 1, 0);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n) rui[i + 1] = a[i] + rui[i];

  ll left = 0, right = INF;
  while(right - left > 1) {
    ll mid     = (right + left) / 2;
    ll vis_cnt = 0;
    rep(i, n) {
      ll idx = lower_bound(a.begin(), a.end(), mid - a[i]) - a.begin();
      vis_cnt += n - idx;
    }
    if(vis_cnt > m) left = mid;
    else right = mid;
  }

  ll ans = 0, vis_cnt = 0;
  rep(i, n) {
    ll idx = upper_bound(a.begin(), a.end(), left - a[i]) - a.begin();
    vis_cnt += n - idx;
    ans += rui[n] - rui[idx] + a[i] * (n - idx);
  }
  ans += (m - vis_cnt) * left;
  cout << ans << endl;

  return 0;
}