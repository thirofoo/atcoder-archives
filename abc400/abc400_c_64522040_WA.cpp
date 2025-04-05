/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64522040
 * Submitted at: 2025-04-05 21:21:20
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_c
 * Result: WA
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

  ll n;
  cin >> n;
  ll ans = 0, tmp = 2;
  while(tmp <= n) {
    ans += ((int) sqrt(n / tmp) + 1) / 2;
    tmp *= 2;
  }
  cout << ans << endl;

  return 0;
}