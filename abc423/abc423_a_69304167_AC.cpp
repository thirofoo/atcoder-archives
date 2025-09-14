/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69304167
 * Submitted at: 2025-09-14 21:06:44
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_a
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

  ll x, c;
  cin >> x >> c;

  ll ans = 0;
  rep(i, 1000000) {
    ll tmp = 1000 * i + i * c;
    if(tmp > x) break;
    ans = 1000 * i;
  }
  cout << ans << "\n";

  return 0;
}