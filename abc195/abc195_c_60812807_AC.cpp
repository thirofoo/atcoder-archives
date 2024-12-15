/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/60812807
 * Submitted at: 2024-12-15 22:37:47
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_c
 * Result: AC
 * Execution Time: 7 ms
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

  ll n, ans = 0, now = 1;
  cin >> n;
  while(true) {
    now *= 1000;
    if(n - now + 1 <= 0) break;
    ans += n - now + 1;
  }
  cout << ans << '\n';

  return 0;
}