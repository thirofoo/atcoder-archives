/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc364/submissions/56015140
 * Submitted at: 2024-07-27 21:14:28
 * Problem URL: https://atcoder.jp/contests/abc364/tasks/abc364_c
 * Result: AC
 * Execution Time: 48 ms
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

  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  ll ans = n, now = 0;
  rep(i, n) {
    now += a[i];
    if(x < now) {
      ans = min(ans, i + 1);
    }
  }
  now = 0;
  rep(i, n) {
    now += b[i];
    if(y < now) {
      ans = min(ans, i + 1);
    }
  }
  cout << ans << '\n';

  return 0;
}