/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc366/submissions/56524420
 * Submitted at: 2024-08-10 21:06:21
 * Problem URL: https://atcoder.jp/contests/abc366/tasks/abc366_c
 * Result: AC
 * Execution Time: 100 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll q; cin >> q;
  map<ll, ll> mp;
  ll ans = 0;
  while(q--) {
    ll t; cin >> t;
    if(t == 1) {
      ll x; cin >> x;
      if(mp[x] == 0) ans++;
      mp[x]++;
    } else if(t == 2) {
      ll x; cin >> x;
      mp[x]--;
      if(mp[x] == 0) ans--;
    } else {
      cout << ans << '\n';
    }
  }
  
  return 0;
}