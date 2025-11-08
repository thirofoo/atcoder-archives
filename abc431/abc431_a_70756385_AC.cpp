/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc431/submissions/70756385
 * Submitted at: 2025-11-08 21:00:54
 * Problem URL: https://atcoder.jp/contests/abc431/tasks/abc431_a
 * Result: AC
 * Execution Time: 10 ms
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

  ll h, b;
  cin >> h >> b;
  cout << max(0LL, h - b) << "\n";

  return 0;
}