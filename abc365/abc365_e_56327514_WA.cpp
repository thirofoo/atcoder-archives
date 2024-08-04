/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56327514
 * Submitted at: 2024-08-04 12:27:30
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_e
 * Result: WA
 * Execution Time: 50 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  // 解説 AC
  // 累積 XOR の各桁における累積和は作らなくてよい
  // ※ 各桁において、(1 の個数) * (0 の個数) * 2^(桁数-1) が寄与になるため

  int n;
  cin >> n;
  vector<int> pa, a(n + 1, 0);
  for(int i = 0; i < n; i++) cin >> a[i + 1];
  pa = a;
  for(int i = 1; i <= n; i++) a[i] ^= a[i - 1];

  int ans = 0;
  for(int i = 0; i < 32; i++) {
    int bit = 0;
    for(int j = 0; j <= n; j++) bit += ((a[j] >> i) & 1);
    ans += bit * (n + 1 - bit) * (1 << i);
  }
  for(int i = 0; i < n; i++) ans -= pa[i + 1];
  cout << ans << '\n';

  return 0;
}