/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65858657
 * Submitted at: 2025-05-17 21:06:44
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_b
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

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  __int128_t ans = 1, base = pow(10, k);
  rep(i, n) {
    ans *= a[i];
    if(ans >= base) ans = 1;
  }
  cout << (ll) ans << endl;

  return 0;
}