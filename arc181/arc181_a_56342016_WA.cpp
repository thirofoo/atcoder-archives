/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc181/submissions/56342016
 * Submitted at: 2024-08-04 21:04:04
 * Problem URL: https://atcoder.jp/contests/arc181/tasks/arc181_a
 * Result: WA
 * Execution Time: 11 ms
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
    vector<ll> p(n);
    bool sorted = true;
    rep(i, n) {
      cin >> p[i];
      sorted &= (i + 1 == p[i]);
    }
    if(sorted) {
      cout << 0 << '\n';
      continue;
    }
    ll max_ele = 0;
    bool f     = false;
    rep(i, n) {
      if(p[i] == i + 1 && max_ele < i + 1) {
        f = true;
        break;
      }
      max_ele = max(max_ele, p[i]);
    }
    cout << (f ? 1 : 2) << '\n';
  }

  return 0;
}