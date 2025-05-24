/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66084041
 * Submitted at: 2025-05-24 21:04:04
 * Problem URL: https://atcoder.jp/contests/abc407/tasks/abc407_a
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

  ll a, b;
  cin >> a >> b;
  ll ans      = 0;
  double diff = INF, cand = (double) a / b;
  for(ll i = -1; i <= 1; i++) {
    if(abs(cand - (double) ((ll) cand - i)) < diff) {
      diff = abs(cand - (double) ((ll) cand - i));
      ans  = (ll) cand - i;
    }
  }
  cout << ans << endl;

  return 0;
}