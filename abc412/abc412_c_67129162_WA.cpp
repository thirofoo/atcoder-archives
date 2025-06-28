/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67129162
 * Submitted at: 2025-06-28 21:09:14
 * Problem URL: https://atcoder.jp/contests/abc412/tasks/abc412_c
 * Result: WA
 * Execution Time: 114 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n;
    cin >> n;
    vector<ll> s(n);
    rep(i, n) cin >> s[i];
    ll start = s[0], end = s.back();

    sort(s.begin(), s.end());
    ll ans = 1;
    while(start < end) {
      auto itr = upper_bound(s.begin(), s.end(), start * 2);
      if(itr == s.begin()) {
        ans = -1;
        break;
      }
      itr--;
      if((*itr) == start) {
        ans = -1;
        break;
      }
      start = (*itr);
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}