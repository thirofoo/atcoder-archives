/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65237865
 * Submitted at: 2025-04-27 21:00:52
 * Problem URL: https://atcoder.jp/contests/abc403/tasks/abc403_a
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  for(ll i = 0; i < n; i += 2) ans += a[i];
  cout << ans << endl;

  return 0;
}