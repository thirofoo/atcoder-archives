/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61543836
 * Submitted at: 2025-01-11 21:02:40
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_b
 * Result: AC
 * Execution Time: 2 ms
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

  ll n, d;
  cin >> n >> d;
  vector<ll> t(n), l(n);
  rep(i, n) cin >> t[i] >> l[i];
  rep(k, d) {
    ll ans        = 0;
    rep(i, n) ans = max(ans, t[i] * (k + 1 + l[i]));
    cout << ans << endl;
  }

  return 0;
}