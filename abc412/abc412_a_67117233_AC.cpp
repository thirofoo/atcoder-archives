/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67117233
 * Submitted at: 2025-06-28 21:01:22
 * Problem URL: https://atcoder.jp/contests/abc412/tasks/abc412_a
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

  ll n;
  cin >> n;
  ll ans = 0;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    ans += (b > a);
  }
  cout << ans << endl;

  return 0;
}