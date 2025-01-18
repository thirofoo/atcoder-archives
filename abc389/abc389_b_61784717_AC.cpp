/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61784717
 * Submitted at: 2025-01-18 21:02:21
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll x, tmp = 1;
  cin >> x;
  for(ll i = 1; i <= 20; i++) {
    tmp *= i;
    if(tmp == x) {
      cout << i << '\n';
      return 0;
    }
  }

  return 0;
}