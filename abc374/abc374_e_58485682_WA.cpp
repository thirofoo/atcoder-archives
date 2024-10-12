/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58485682
 * Submitted at: 2024-10-05 22:39:59
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_e
 * Result: WA
 * Execution Time: 2 ms
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
      // lcm くらいまでは効率重視で ok
      ll cand1 = 0, lcm = LCM(a[i], b[i]);
      ll first = m1 - (m1 % lcm);
      if(a[i] * q[i] >= b[i] * p[i]) cand1 += (first / a[i]) * p[i];
      else cand1 += (first / b[i]) * q[i];

      // それ以降は全探索
      ll rest  = m1 - first;
      ll a_num = 0, cand2 = 1e10;
      while(true) {
        cand2 = min(cand2, a_num * p[i] + ((max(rest - a_num * a[i], 0LL) + b[i] - 1) / b[i]) * q[i]);
        if(a_num * a[i] >= rest) break;
        a_num++;
      }
      ll b_num = 0;
      while(true) {
        cand2 = min(cand2, b_num * q[i] + ((max(rest - b_num * b[i], 0LL) + a[i] - 1) / a[i]) * p[i]);
        if(b_num * b[i] >= rest) break;
        b_num++;
      }
      sum += cand1 + cand2;
      if(sum > x) break;
      // cerr << i << ' ' << sum << endl;
    }
    // cerr << l1 << ' ' << r1 << ' ' << m1 << ' ' << sum << endl;
    if(sum <= x) l1 = m1;
    else r1 = m1;
  }
  cout << l1 << endl;

  return 0;
}