/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64504528
 * Submitted at: 2025-04-05 21:03:54
 * Problem URL: https://atcoder.jp/contests/abc400/tasks/abc400_b
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

  ll n, m;
  cin >> n >> m;
  ll ans = 0, now = 1;
  bool ng = false;
  rep(i, m + 1) {
    if(now > 1000000000) {
      ng = true;
      break;
    }
    ans += now;
    now *= n;
  }
  cout << (ng || ans > 1000000000 ? "inf" : to_string(ans)) << endl;

  return 0;
}