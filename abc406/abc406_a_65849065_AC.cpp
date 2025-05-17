/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65849065
 * Submitted at: 2025-05-17 21:01:54
 * Problem URL: https://atcoder.jp/contests/abc406/tasks/abc406_a
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

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  bool ok = ((c < a) || (c == a && d < b));
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}