/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59348623
 * Submitted at: 2024-11-02 21:02:17
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_a
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

  ll a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  map<ll, ll> m;
  m[a1]++;
  m[a2]++;
  m[a3]++;
  m[a4]++;
  ll ans = 0;
  for(auto [key, value]: m) {
    ans += value / 2;
  }
  cout << ans << '\n';

  return 0;
}