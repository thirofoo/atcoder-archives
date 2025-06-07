/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66508383
 * Submitted at: 2025-06-07 21:03:04
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_b
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans                          = 0;
  rep(i, n) if(n - i >= a[i]) ans = max(ans, a[i]);
  cout << ans << endl;

  return 0;
}