/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc454/submissions/75034915
 * Submitted at: 2026-04-18 21:00:22
 * Problem URL: https://atcoder.jp/contests/abc454/tasks/abc454_a
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll l, r;
  cin >> l >> r;
  cout << r - l + 1 << endl;

  return 0;
}