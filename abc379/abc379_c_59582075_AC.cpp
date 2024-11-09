/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59582075
 * Submitted at: 2024-11-09 21:19:35
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_c
 * Result: AC
 * Execution Time: 37 ms
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
  vector<ll> x(m), a(m);
  rep(i, m) {
    cin >> x[i];
    x[i]--;
  }
  ll total = 0, ans = (1 + n) * n / 2;
  rep(i, m) {
    cin >> a[i];
    total += a[i];
    ans -= (x[i] + 1) * a[i];
  }
  if(total != n) return cout << -1 << endl, 0;

  bool flag = true;
  vector<ll> p(m, 0);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](ll i, ll j) {
    return x[i] > x[j];
  });
  ll sum = 0;
  rep(i, m) {
    sum += a[p[i]];
    flag &= (sum <= n - x[p[i]]);
    // cerr << sum << endl;
  }
  if(flag) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}