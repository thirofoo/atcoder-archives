/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66717258
 * Submitted at: 2025-06-14 21:01:05
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_a
 * Result: CE
 * Execution Time: None ms
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
  ll k, ans = 0;
  cin >> k;
  rep(i, n) ans += (a[i] >= k);
  cout << ans << endl;

  return 0;
}