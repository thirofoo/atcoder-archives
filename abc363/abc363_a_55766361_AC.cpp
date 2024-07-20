/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55766361
 * Submitted at: 2024-07-20 21:01:17
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_a
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

  ll r; cin >> r;
  cout << (100 - r%100) << endl;

  return 0;
}