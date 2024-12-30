/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/61254699
 * Submitted at: 2024-12-30 22:39:22
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_d
 * Result: AC
 * Execution Time: 20 ms
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
  cout << setprecision(10) << fixed;

  ll n, k;
  cin >> n >> k;
  vector<double> p(n);
  double ans = 0.0, cand = 0.0;
  rep(i, n) cin >> p[i];
  rep(i, k) cand += (1.0 + p[i]) / 2.0;
  for(ll i = 0; i + k <= n; i++) {
    ans = max(ans, cand);
    if(i + k < n) cand += (1.0 + p[i + k]) / 2.0 - (1.0 + p[i]) / 2.0;
  }
  cout << ans << endl;

  return 0;
}