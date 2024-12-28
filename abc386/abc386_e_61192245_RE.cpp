/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc386/submissions/61192245
 * Submitted at: 2024-12-28 22:17:59
 * Problem URL: https://atcoder.jp/contests/abc386/tasks/abc386_e
 * Result: RE
 * Execution Time: 97 ms
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
  vector<ll> a(n, 0);
  rep(i, n) cin >> a[i];

  bool reverse = (2 * k >= n);
  ll base      = 0;
  if(reverse) {
    k = n - k;
    rep(i, n) base ^= a[i];
  }
  vector<ll> perm(k);
  iota(perm.begin(), perm.end(), 0);
  ll ans = 0;
  while(perm[0] <= n - k) {
    ll xor_sum = base;
    rep(i, k) xor_sum ^= a[perm[i]];
    ans = max(ans, xor_sum);
    perm[k - 1]++;
    for(ll i = k - 1; i >= 1; i--) {
      if(perm[i] >= n - (k - 1 - i)) {
        perm[i] = 0;
        perm[i - 1]++;
      } else break;
    }
    for(ll i = 1; i < k; i++) {
      perm[i] = max(perm[i], perm[i - 1] + 1);
    }
  }
  cout << ans << '\n';

  return 0;
}