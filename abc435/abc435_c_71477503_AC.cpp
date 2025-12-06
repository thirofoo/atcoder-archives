/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71477503
 * Submitted at: 2025-12-06 21:08:24
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_c
 * Result: AC
 * Execution Time: 19 ms
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = a[0];
  for(ll i = 1; i < n; i++) {
    if(ans <= i) break;
    ans = max(ans, a[i] + i);
  }
  cout << min(ans, n) << "\n";

  return 0;
}