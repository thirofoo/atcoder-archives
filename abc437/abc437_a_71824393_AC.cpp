/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71824393
 * Submitted at: 2025-12-20 21:00:49
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_a
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

  ll a, b;
  cin >> a >> b;
  cout << a * 12 + b << "\n";

  return 0;
}