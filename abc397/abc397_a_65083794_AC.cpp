/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65083794
 * Submitted at: 2025-04-21 19:30:56
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_a
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

  double x;
  cin >> x;
  cout << (x >= 38.0 ? 1 : (x >= 37.5 ? 2 : 3)) << endl;

  return 0;
}