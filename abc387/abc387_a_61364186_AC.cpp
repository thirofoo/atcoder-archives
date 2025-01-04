/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61364186
 * Submitted at: 2025-01-04 21:00:49
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_a
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

  ll a, b;
  cin >> a >> b;
  cout << (a + b) * (a + b) << '\n';

  return 0;
}