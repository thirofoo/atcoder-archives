/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc086/submissions/60812818
 * Submitted at: 2024-12-15 22:38:03
 * Problem URL: https://atcoder.jp/contests/abc086/tasks/arc089_a
 * Result: AC
 * Execution Time: 12 ms
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
  vector<ll> t(n), x(n), y(n);
  rep(i, n) cin >> t[i] >> x[i] >> y[i];

  ll now_x = 0, now_y = 0, now_t = 0;
  rep(i, n) {
    bool ng = false;
    ll dis  = abs(x[i] - now_x) + abs(y[i] - now_y);
    ng |= (dis > t[i] - now_t || (t[i] - now_t) % 2 != dis % 2);
    if(ng) {
      cout << "No" << '\n';
      return 0;
    }
    now_x = x[i];
    now_y = y[i];
    now_t = t[i];
  }
  cout << "Yes" << '\n';

  return 0;
}