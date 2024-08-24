/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57045305
 * Submitted at: 2024-08-24 21:12:25
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_c
 * Result: AC
 * Execution Time: 13 ms
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
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  ll ans = 0;
  rep(i, n) {
    ans += (h[i] / 5) * 3;
    ll rest = h[i] % 5;
    if(ans % 3 == 0) {
      if(rest <= 0) continue;
      else if(rest <= 1) ans++;
      else if(rest <= 2) ans += 2;
      else ans += 3;
    } else if(ans % 3 == 1) {
      if(rest <= 0) continue;
      else if(rest <= 1) ans++;
      else if(rest <= 4) ans += 2;
      else ans += 3;
    } else {
      if(rest <= 0) continue;
      else if(rest <= 3) ans++;
      else if(rest <= 4) ans += 2;
      else ans += 3;
    }
  }
  cout << ans << '\n';

  return 0;
}