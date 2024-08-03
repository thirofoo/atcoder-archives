/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56285251
 * Submitted at: 2024-08-03 21:45:47
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_e
 * Result: AC
 * Execution Time: 64 ms
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
  vector<ll> pa, a(n + 1, 0);
  rep(i, n) cin >> a[i + 1];
  pa = a;
  for(int i = 1; i <= n; i++) a[i] ^= a[i - 1];
  vector<vector<ll>> dig(32, vector<ll>(n + 1, 0));
  for(int i = 0; i < 32; i++) {
    for(int j = 1; j <= n; j++) {
      dig[i][j] = (a[j] >> i) & 1;
      dig[i][j] += dig[i][j - 1];
    }
  }

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 32; j++) {
      if((a[i] >> j) & 1) {
        // bit が立ってない場所が立つ、立ってる場所が立たない
        ll num = (n - i - (dig[j][n] - dig[j][i]));
        ans += (1LL << j) * num;
      } else {
        ll num = (dig[j][n] - dig[j][i]);
        ans += (1LL << j) * num;
      }
    }
  }
  rep(i, n) ans -= pa[i + 1];
  cout << ans << '\n';

  return 0;
}