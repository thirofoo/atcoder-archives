/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66728012
 * Submitted at: 2025-06-14 21:07:46
 * Problem URL: https://atcoder.jp/contests/abc410/tasks/abc410_c
 * Result: AC
 * Execution Time: 332 ms
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

  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  iota(a.begin(), a.end(), 1);
  ll start = 0;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll p, x;
      cin >> p >> x;
      p--;
      a[(start + p) % n] = x;
    } else if(t == 2) {
      ll p;
      cin >> p;
      p--;
      cout << a[(start + p) % n] << endl;
    } else {
      ll k;
      cin >> k;
      start = (start + k) % n;
    }
  }

  return 0;
}