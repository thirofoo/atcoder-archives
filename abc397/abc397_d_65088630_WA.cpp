/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65088630
 * Submitted at: 2025-04-21 22:33:10
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
 * Result: WA
 * Execution Time: 470 ms
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

  using ld = long double;

  ll n;
  cin >> n;
  for(ld t = 1; t <= 1000005; t++) {
    if(t * t * t > n) break;
    ld left = 1, right = (n - t * t * t) / (3 * t) + 5;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      if(t * t * t + 3 * mid * t <= n) left = mid;
      else right = mid;
    }
    // cerr << "t: " << t << " st: " << left << " val: " << t * t * t + 3 * left * t << endl;
    if(t * t * t + 3 * left * t == n) {
      ll y = -(ld) (t / 2) + sqrt((ld) (t / 2) * (ld) (t / 2) + left);
      ll x = cbrt(n + (ld) y * y * y);
      cout << x << " " << y << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}