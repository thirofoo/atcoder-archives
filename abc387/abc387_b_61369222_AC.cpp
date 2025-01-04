/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc387/submissions/61369222
 * Submitted at: 2025-01-04 21:02:25
 * Problem URL: https://atcoder.jp/contests/abc387/tasks/abc387_b
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

  ll x;
  cin >> x;
  ll ans = 0;
  for(ll i = 1; i <= 9; i++)
    for(ll j = 1; j <= 9; j++) {
      if(i * j == x) continue;
      ans += i * j;
    }
  cout << ans << '\n';

  return 0;
}