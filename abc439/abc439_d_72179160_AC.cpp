/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc439/submissions/72179160
 * Submitted at: 2026-01-03 21:12:07
 * Problem URL: https://atcoder.jp/contests/abc439/tasks/abc439_d
 * Result: AC
 * Execution Time: 484 ms
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

  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, vector<ll>> mp;
  rep(i, n) {
    cin >> a[i];
    mp[a[i]].emplace_back(i);
  }
  ll ans = 0;
  rep(j, n) {
    if(a[j] % 5 != 0) continue;
    ll target1 = a[j] / 5 * 7, target2 = a[j] / 5 * 3;
    ll lower_num1 = lower_bound(mp[target1].begin(), mp[target1].end(), j) - mp[target1].begin();
    ll lower_num2 = lower_bound(mp[target2].begin(), mp[target2].end(), j) - mp[target2].begin();
    ans += lower_num1 * lower_num2;
    ll upper_num1 = mp[target1].end() - upper_bound(mp[target1].begin(), mp[target1].end(), j);
    ll upper_num2 = mp[target2].end() - upper_bound(mp[target2].begin(), mp[target2].end(), j);
    ans += upper_num1 * upper_num2;
  }
  cout << ans << "\n";

  return 0;
}