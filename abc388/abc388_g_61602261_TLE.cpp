/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc388/submissions/61602261
 * Submitted at: 2025-01-11 22:38:12
 * Problem URL: https://atcoder.jp/contests/abc388/tasks/abc388_g
 * Result: TLE
 * Execution Time: 2208 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll q;
  cin >> q;
  while(q--) {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    ll mid  = r - l + 1;
    ll half = mid / 2;
    ll i = l, j = l + half, ans = 0;
    while(i < l + half && j <= r) {
      if(2LL * a[i] <= a[j]) {
        ans++;
        i++;
        j++;
      } else {
        j++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
