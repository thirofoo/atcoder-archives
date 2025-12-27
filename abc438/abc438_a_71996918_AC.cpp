/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/71996918
 * Submitted at: 2025-12-27 21:03:34
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_a
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

  ll d, f;
  cin >> d >> f;
  ll ans = 7 - ((d - f) % 7);
  cout << ans << "\n";

  return 0;
}