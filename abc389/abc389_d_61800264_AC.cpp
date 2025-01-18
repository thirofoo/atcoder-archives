/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61800264
 * Submitted at: 2025-01-18 21:15:30
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_d
 * Result: AC
 * Execution Time: 8 ms
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
  ll r, x;
  cin >> r;
  x      = r;
  ll ans = 0;
  for(ld y = 1; y <= r; y++) {
    while(true) {
      ld dist = ((ld) 0.5 - (ld) x) * ((ld) 0.5 - (ld) x) + ((ld) 0.5 - (ld) y) * ((ld) 0.5 - (ld) y);
      if(dist <= (ld) r * r) break;
      x -= 1;
    }
    ans += x - 1;
  }
  cout << ans * 4 + 1 << '\n';

  return 0;
}