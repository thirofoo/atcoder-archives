/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66090198
 * Submitted at: 2025-05-24 21:07:51
 * Problem URL: https://atcoder.jp/contests/abc407/tasks/abc407_b
 * Result: AC
 * Execution Time: 1 ms
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

  cout << setprecision(15) << fixed;
  ll x, y;
  cin >> x >> y;
  double ans = 0.0;
  rep(i, 6) rep(j, 6) {
    bool ok = false;
    ok |= (i + j + 2 >= x);
    ok |= (abs(i - j) >= y);
    if(ok) {
      ans += 1.0;
      // cerr << "i: " << i << ", j: " << j << endl;
    }
  }
  cout << ans / 36.0 << endl;

  return 0;
}