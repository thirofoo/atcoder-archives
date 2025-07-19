/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67734730
 * Submitted at: 2025-07-19 21:45:09
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_d
 * Result: AC
 * Execution Time: 137 ms
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
    ll left = 0, right = INF;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      // bool flag = ((n + b[p[i]] * mid) - (a[p[i]] * mid) >= a[p[i]]);
      bool flag = ((b[p[i]] - a[p[i]]) >= (a[p[i]] - n) / mid);
      if(flag) left = mid;
      else right = mid;
    }
    if(left == 0 && n < a[p[i]]) continue;
    ans += left + 1;
    n -= a[p[i]] * (left + 1);
    n += b[p[i]] * (left + 1);
  }
  cout << ans << endl;

  return 0;
}