/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58674696
 * Submitted at: 2024-10-12 21:04:32
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_b
 * Result: AC
 * Execution Time: 56 ms
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
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;
  vector<double> x(n + 1), y(n + 1);
  rep(i, n) cin >> x[i + 1] >> y[i + 1];
  x.emplace_back(0.0);
  y.emplace_back(0.0);
  double ans = 0.0;
  rep(i, n + 1) {
    ans += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
  }
  cout << ans << '\n';

  return 0;
}