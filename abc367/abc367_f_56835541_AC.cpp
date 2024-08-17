/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56835541
 * Submitted at: 2024-08-17 23:05:47
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_f
 * Result: AC
 * Execution Time: 249 ms
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

inline unsigned int rand_int() {
  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
  unsigned int tt = (tx ^ (tx << 11));
  tx = ty, ty = tz, tz = tw;
  return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> a(n + 1), b(n + 1);
  map<ll, ll> hash;
  ll T = 1000000007;
  rep(i, n) {
    cin >> a[i + 1];
    if(!hash.count(a[i + 1])) {
      hash[a[i + 1]] = rand_int() % T;
    }
    a[i + 1] = hash[a[i + 1]] + a[i];
  }
  rep(i, n) {
    cin >> b[i + 1];
    if(!hash.count(b[i + 1])) {
      hash[b[i + 1]] = rand_int() % T;
    }
    b[i + 1] = hash[b[i + 1]] + b[i];
  }

  while(q--) {
    ll l, r, L, R;
    cin >> l >> r >> L >> R;
    cout << (a[r] - a[l - 1] == b[R] - b[L - 1] ? "Yes" : "No") << '\n';
  }

  return 0;
}