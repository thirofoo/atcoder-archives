/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc435/submissions/71473430
 * Submitted at: 2025-12-06 21:04:47
 * Problem URL: https://atcoder.jp/contests/abc435/tasks/abc435_b
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

  ll n;
  cin >> n;
  vector<ll> a(n), rui(n + 1, 0);
  rep(i, n) {
    cin >> a[i];
    rui[i + 1] = rui[i] + a[i];
  }
  ll ans = 0;
  rep(l, n) for(ll r = l + 1; r <= n; r++) {
    ll sum    = rui[r] - rui[l];
    bool flag = true;
    for(ll i = l; i < r; i++) {
      flag &= (sum % a[i] != 0);
    }
    if(flag) ans++;
  }
  cout << ans << "\n";

  return 0;
}