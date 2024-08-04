/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56327533
 * Submitted at: 2024-08-04 12:28:08
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_e
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  // 解説 AC
  // 累積 XOR の各桁における累積和は作らなくてよい
  // ※ 各桁において、(1 の個数) * (0 の個数) * 2^(桁数-1) が寄与になるため

  using ll = long long;
  ll n;
  cin >> n;
  vector<ll> pa, a(n + 1, 0);
  for(ll i = 0; i < n; i++) cin >> a[i + 1];
  pa = a;
  for(ll i = 1; i <= n; i++) a[i] ^= a[i - 1];

  ll ans = 0;
  for(ll i = 0; i < 32; i++) {
    ll bit = 0;
    for(ll j = 0; j <= n; j++) bit += ((a[j] >> i) & 1);
    ans += bit * (n + 1 - bit) * (1 << i);
  }
  for(ll i = 0; i < n; i++) ans -= pa[i + 1];
  cout << ans << '\n';

  return 0;
}