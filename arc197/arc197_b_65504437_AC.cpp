/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc197/submissions/65504437
 * Submitted at: 2025-05-04 21:27:21
 * Problem URL: https://atcoder.jp/contests/arc197/tasks/arc197_b
 * Result: AC
 * Execution Time: 54 ms
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

  using ld = long double;

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<ll> a(n), rui(n + 1, 0);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, n) rui[i + 1] = rui[i] + a[i];

    ll ans = 0;
    for(ll i = 1; i < n; i++) {
      ll left = i - 1, right = n + 1;
      while(right - left > 1) {
        ll mid = (left + right) / 2;
        ld ave = rui[mid] / (ld) mid;
        if((ld) a[i] > ave) left = mid;
        else right = mid;
      }
      // cerr << "i: " << i << " left: " << left << " right: " << right << '\n';
      ans = max(ans, left - i);
    }
    cout << ans << '\n';
  }

  return 0;
}