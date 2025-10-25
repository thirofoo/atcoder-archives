/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70434724
 * Submitted at: 2025-10-25 21:28:21
 * Problem URL: https://atcoder.jp/contests/abc429/tasks/abc429_d
 * Result: AC
 * Execution Time: 1172 ms
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

  ll n, m, c;
  cin >> n >> m >> c;
  vector<ll> a(n);
  ll max_ele = -INF;
  rep(i, n) {
    cin >> a[i];
    if(a[i] == 0) a[i] = m;
    max_ele = max(max_ele, a[i]);
  }
  rep(i, n) a.emplace_back(a[i] + m);
  sort(a.begin(), a.end());
  while(max_ele > 0) max_ele -= m;

  ll ans = 0, prev = max_ele;
  // cerr << "max_ele: " << max_ele << '\n';
  rep(i, n) {
    ll left = a[i], right = INF;
    auto start = lower_bound(a.begin(), a.end(), a[i]);
    while(left < right) {
      ll mid   = (left + right) / 2;
      auto end = lower_bound(a.begin(), a.end(), mid);
      ll cnt   = (ll) (end - start);
      if(cnt >= c) right = mid;
      else left = mid + 1;
    }
    auto end = lower_bound(a.begin(), a.end(), right);
    ll cnt   = (ll) (end - start);
    ans += cnt * (a[i] - prev);
    prev = a[i];
    // cerr << "i: " << i << ", left: " << left << ", right: " << right << ", cnt: " << cnt << ", ans: " << ans << ", prev: " << prev << '\n';
  }
  cout << ans << '\n';

  return 0;
}