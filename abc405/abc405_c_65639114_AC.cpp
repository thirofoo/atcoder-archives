/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65639114
 * Submitted at: 2025-05-10 21:05:11
 * Problem URL: https://atcoder.jp/contests/abc405/tasks/abc405_c
 * Result: AC
 * Execution Time: 14 ms
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
  vector<ll> a(n), rui(n + 1);
  rep(i, n) {
    cin >> a[i];
    rui[i + 1] = rui[i] + a[i];
  }
  ll ans = 0;
  rep(i, n) ans += a[i] * (rui[n] - rui[i + 1]);
  cout << ans << endl;

  return 0;
}