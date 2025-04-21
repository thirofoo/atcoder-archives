/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65090140
 * Submitted at: 2025-04-21 23:26:33
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
 * Result: WA
 * Execution Time: 139 ms
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
  for(ll t = 1; t <= 1e6 + 5; t++) {
    ll left = 1, right = 1e9 + 5;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      if(3 * t * mid * mid + 3 * t * t * mid - n + t * t * t <= 0) left = mid;
      else right = mid;
    }
    ll y = left, x = t + y;
    if(x * x * x - y * y * y == n) {
      cout << (ll) x << " " << (ll) y << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}