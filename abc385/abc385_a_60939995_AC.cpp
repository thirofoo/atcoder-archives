/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60939995
 * Submitted at: 2024-12-21 21:01:36
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_a
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

  ll a, b, c;
  cin >> a >> b >> c;
  bool flag = false;
  flag |= (a == b + c);
  flag |= (b == a + c);
  flag |= (c == a + b);
  flag |= (a == b && b == c);
  cout << (flag ? "Yes" : "No") << '\n';

  return 0;
}