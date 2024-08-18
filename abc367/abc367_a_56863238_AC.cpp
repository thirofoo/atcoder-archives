/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56863238
 * Submitted at: 2024-08-18 19:05:50
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_a
 * Result: AC
 * Execution Time: 5 ms
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

  ll a, b, c;
  cin >> a >> b >> c;
  swap(b, c);
  if(c < b) c += 24;
  bool f = false;
  f |= (b < a && a < c);
  a += 24;
  f |= (b < a && a < c);
  cout << (f ? "Yes" : "No") << '\n';

  return 0;
}