/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc385/submissions/60989885
 * Submitted at: 2024-12-21 22:36:59
 * Problem URL: https://atcoder.jp/contests/abc385/tasks/abc385_f
 * Result: WA
 * Execution Time: 23 ms
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
  vector<ll> x(n), h(n);
  rep(i, n) cin >> x[i] >> h[i];
  bool ng  = true;
  using ld = long double;
  ld pre   = (ld) h[0] / x[0]; 
  rep(i, n - 1) {
    ld new_a = (ld) (h[i + 1] - h[i]) / (x[i + 1] - x[i]);
    ng &= (new_a > pre);
    pre = new_a;
  }
  if(ng) return cout << -1 << '\n', 0;

  auto calc_height = [&](ll idx) -> ld {
    ld res = h[idx];
    res -= (ld) x[idx] * (h[idx + 1] - h[idx]) / (x[idx + 1] - x[idx]);
    return res;
  };
  ld ans = -1e12;
  rep(i, n - 1) {
    ans = max(ans, (ld) calc_height(i));
    // cerr << "i: " << i << ", calc_height(i): " << calc_height(i) << '\n';
  }
  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}