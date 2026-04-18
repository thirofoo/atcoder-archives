/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc454/submissions/75079177
 * Submitted at: 2026-04-18 22:08:25
 * Problem URL: https://atcoder.jp/contests/abc454/tasks/abc454_e
 * Result: WA
 * Execution Time: 5 ms
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
    ll n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    if(n % 2 == 1) {
      cout << "No" << endl;
      continue;
    }

    string ans;
    ll r = (a % 2 == 0 ? a : a - 1);

    for(ll i = 0; i < r; i += 2) {
      rep(j, n - 1) ans += 'R';
      ans += 'D';
      rep(j, n - 1) ans += 'L';
      ans += 'D';
    }

    if(a % 2 == 0) {
      for(ll j = 0; j < b - 1; j += 2) ans += "DRUR";
      ans += "DR";
      for(ll j = b + 2; j < n; j += 2) ans += "RURD";
    } else {
      for(ll j = 0; j < b; j += 2) ans += "DRUR";
      ans += "RD";
      for(ll j = b + 3; j < n; j += 2) ans += "RURD";
    }

    for(ll i = r + 2; i < n; i += 2) {
      ans += 'D';
      rep(j, n - 1) ans += 'L';
      ans += 'D';
      rep(j, n - 1) ans += 'R';
    }

    cout << "Yes" << endl;
    cout << ans << endl;
  }

  return 0;
}