/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67728448
 * Submitted at: 2025-07-19 21:30:28
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_d
 * Result: TLE
 * Execution Time: 2208 ms
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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m), p(m, 0);
  rep(i, m) cin >> a[i] >> b[i];

  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](ll i, ll j) {
    if(a[i] - b[i] != a[j] - b[j]) return a[i] - b[i] < a[j] - b[j];
    return a[i] < a[j];
  });

  ll ans = 0;
  rep(i, m) {
    while(n >= a[p[i]]) {
      ll add = n / a[p[i]];
      ans += add;
      n -= add * a[p[i]];
      n += add * b[p[i]];
    }
  }
  cout << ans << endl;

  return 0;
}