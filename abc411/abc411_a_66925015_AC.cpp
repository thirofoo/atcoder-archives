/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66925015
 * Submitted at: 2025-06-21 21:00:57
 * Problem URL: https://atcoder.jp/contests/abc411/tasks/abc411_a
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

  string p;
  ll l;
  cin >> p >> l;
  cout << ((ll) p.size() >= l ? "Yes" : "No") << endl;

  return 0;
}