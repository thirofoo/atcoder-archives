/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58435745
 * Submitted at: 2024-10-05 21:03:44
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_c
 * Result: AC
 * Execution Time: 65 ms
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
  
  ll n;
  cin >> n;
  vector<ll> k(n);
  rep(i, n) cin >> k[i];
  ll ans = INF;
  rep(i, (1LL << n)) {
    ll a = 0, b = 0;
    rep(j, n) {
      if(i & (1LL << j)) a += k[j];
      else b += k[j];
    }
    ans = min(ans, max(a, b));
  }
  cout << ans << endl;
  
  return 0;
}