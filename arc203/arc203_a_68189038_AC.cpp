/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc203/submissions/68189038
 * Submitted at: 2025-08-03 21:13:42
 * Problem URL: https://atcoder.jp/contests/arc203/tasks/arc203_a
 * Result: AC
 * Execution Time: 35 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n, m;
    cin >> n >> m;
    cout << (m / 2) * (n - 1) + (m + 1) / 2 << '\n';
  }

  return 0;
}