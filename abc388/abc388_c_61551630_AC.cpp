/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61551630
 * Submitted at: 2025-01-11 21:07:29
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_c
 * Result: AC
 * Execution Time: 45 ms
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
  rep(i, n) {
    ans += a.size() - (lower_bound(a.begin(), a.end(), a[i] * 2) - a.begin());
    // cerr << ans << endl;
  }
  cout << ans << endl;

  return 0;
}