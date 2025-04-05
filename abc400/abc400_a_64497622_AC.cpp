/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64497622
 * Submitted at: 2025-04-05 21:01:07
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_a
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

  ll a;
  cin >> a;
  if(400 % a != 0) cout << -1 << endl;
  else {
    ll b = 400 / a;
    cout << b << endl;
  }

  return 0;
}