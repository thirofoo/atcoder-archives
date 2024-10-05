/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc374/submissions/58474826
 * Submitted at: 2024-10-05 22:09:40
 * Problem URL: https://atcoder.jp/contests/abc374/tasks/abc374_e
 * Result: WA
 * Execution Time: 1 ms
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

  ll n, x;
  cin >> n >> x;
  vector<ll> a(n), p(n), b(n), q(n);
  rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

  ll l1 = 0, r1 = 1e9 + 5;
  while(r1 - l1 > 1) {
    ll m1  = (l1 + r1) / 2;
    ll sum = 0, rest;
    rep(i, n) {
      ll cand = 0;
      if(a[i] * q[i] >= b[i] * p[i]) {
        cand += (m1 / a[i]) * p[i];
        rest = m1 % a[i];
        if(rest) cand += min(p[i], ((rest + b[i] - 1) / b[i]) * q[i]);
      } else {
        cand += (m1 / b[i]) * q[i];
        rest = m1 % b[i];
        if(rest) cand += min(q[i], ((rest + a[i] - 1) / a[i]) * p[i]);
      }
      // 片方に偏るケースも考える
      cand = min(cand, (m1 + a[i] - 1) / a[i] * p[i]);
      cand = min(cand, (m1 + b[i] - 1) / b[i] * q[i]);
      sum += cand;
      // cerr << i << ' ' << sum << endl;
    }
    // cerr << l1 << ' ' << r1 << ' ' << m1 << ' ' << sum << endl;
    if(sum <= x) l1 = m1;
    else r1 = m1;
  }
  cout << l1 << endl;

  return 0;
}