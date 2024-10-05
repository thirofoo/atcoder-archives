/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58492807
 * Submitted at: 2024-10-06 00:18:11
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_e
 * Result: AC
 * Execution Time: 3 ms
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

inline long long LCM(long long a, long long b) {
    // overflow 時は return -1 (std::lcm は overflow する)
    if( (a / gcd(a,b)) >= 1e18 / b ) return -1;
    return a  / gcd(a,b) * b;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n), p(n), b(n), q(n);
  rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

  ll l1 = 0, r1 = 1e9 + 5;
  while(r1 - l1 > 1) {
    ll m1  = (l1 + r1) / 2;
    ll sum = 0;
    rep(i, n) {
      ll cand = INF;
      ll lcm = LCM(a[i], b[i]);
      rep(j, lcm / a[i]) cand = min(cand, p[i] * j + max(0LL, m1 - a[i] * j + b[i] - 1) / b[i] * q[i]);
      rep(j, lcm / b[i]) cand = min(cand, q[i] * j + max(0LL, m1 - b[i] * j + a[i] - 1) / a[i] * p[i]);
      sum += cand;
    }
    if(sum <= x) l1 = m1;
    else r1 = m1;
  }
  cout << l1 << endl;

  return 0;
}