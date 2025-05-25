/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc198/submissions/66162963
 * Submitted at: 2025-05-25 21:49:02
 * Problem URL: https://atcoder.jp/contests/arc198/tasks/arc198_b
 * Result: WA
 * Execution Time: 224 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll x, y, z;
    cin >> x >> y >> z;
    if(x == 0 || z > x) {
      cout << "No" << endl;
      continue;
    }
    if(z == x) {
      cout << (z + x > y ? "No" : "Yes") << endl;
      continue;
    }
    x -= z;
    y -= 2 * z;
    if(y <= 2 * x) {
      cout << (z == 0 && y % 2 == 1 ? "No" : "Yes") << endl;
    } else cout << "No" << endl;
  }

  return 0;
}