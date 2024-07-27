/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56022676
 * Submitted at: 2024-07-27 21:23:14
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_d
 * Result: AC
 * Execution Time: 875 ms
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

  ll n, q;
  cin >> n >> q;
  vector<ll> a1(n), a2;
  rep(i, n) {
    cin >> a1[i];
    a2.emplace_back(-a1[i]);
  }
  sort(a1.begin(), a1.end());
  sort(a2.begin(), a2.end());

  while(q--) {
    ll b, k;
    cin >> b >> k;
    ll left = -INF, right = INF;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      ll cnt = 0;
      cnt += upper_bound(a1.begin(), a1.end(), b + mid) - lower_bound(a1.begin(), a1.end(), b);
      cnt += upper_bound(a2.begin(), a2.end(), -b + mid) - lower_bound(a2.begin(), a2.end(), -b);
      cnt -= upper_bound(a1.begin(), a1.end(), b) - lower_bound(a1.begin(), a1.end(), b);
      if(cnt < k) left = mid;
      else right = mid;
    }
    cout << right << '\n';
  }

  return 0;
}