/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc414/submissions/67561212
 * Submitted at: 2025-07-12 22:55:21
 * Problem URL: https://atcoder.jp/contests/abc414/tasks/abc414_e
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
  mint tmp  = 0;
  ll sqrt_n = sqrt(n);
  for(ll i = 1; i <= sqrt_n; i++) {
    tmp += mint(n / i);
  }
  mint ans = mint(n) * (n + 1) / 2 - 2 * tmp + sqrt_n * sqrt_n;
  cout << ans.val() << endl;

  return 0;
}