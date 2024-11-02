/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc378/submissions/59356114
 * Submitted at: 2024-11-02 21:08:21
 * Problem URL: https://atcoder.jp/contests/abc378/tasks/abc378_b
 * Result: AC
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

  ll n;
  cin >> n;
  vector<ll> q(n), r(n);
  rep(i, n) cin >> q[i] >> r[i];

  ll Q;
  cin >> Q;
  while(Q--) {
    ll t, d;
    cin >> t >> d;
    t--;
    ll add = (q[t] + (r[t] - d) % q[t]) % q[t];
    cout << d + add << endl;
  }

  return 0;
}