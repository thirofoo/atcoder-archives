/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc423/submissions/69348142
 * Submitted at: 2025-09-14 22:38:55
 * Problem URL: https://atcoder.jp/contests/abc423/tasks/abc423_f
 * Result: AC
 * Execution Time: 55 ms
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

  ll n, m, y;
  cin >> n >> m >> y;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<ll>> comb(n + 1, vector<ll>(n + 1, 0));
  rep(i, n + 1) {
    comb[i][0] = 1;
    for(ll j = 1; j <= i; j++) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }

  ll size = 1LL << n;
  vector<ll> lcm_mask(size, 1);
  lcm_mask[0] = 1;
  for(ll mask = 1; mask < size; mask++) {
    ll p = -1;
    rep(i, n) {
      if((mask >> i) & 1) {
        p = i;
        break;
      }
    }

    ll prev = mask & (mask - 1);
    ll l    = lcm_mask[prev];
    if(l > y) lcm_mask[mask] = y + 1;
    else {
      if(l / gcd(l, a[p]) > y / a[p]) lcm_mask[mask] = y + 1;
      else lcm_mask[mask] = (l / gcd(l, a[p])) * a[p];
    }
  }

  ll ans = 0;
  for(ll mask = 1; mask < size; mask++) {
    ll k = __builtin_popcountll((ull) mask);
    if(k < m) continue;

    ll l = lcm_mask[mask];
    if(l > y) continue;

    ll cnt = y / l, c = comb[k][m], sgn = ((k - m) % 2 == 0) ? 1 : -1;
    ans += (ll) sgn * (ll) c * (ll) cnt;
  }
  cout << ans << '\n';

  return 0;
}
