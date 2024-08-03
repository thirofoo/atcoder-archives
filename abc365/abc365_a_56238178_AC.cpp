/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc365/submissions/56238178
 * Submitted at: 2024-08-03 21:01:05
 * Problem URL: https://atcoder.jp/contests/abc365/tasks/abc365_a
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll y; cin >> y;
  if(y % 4 != 0) cout << 365 << endl;
  else if(y % 100 != 0) cout << 366 << endl;
  else if(y % 400 != 0) cout << 365 << endl;
  else cout << 366 << endl;
  
  return 0;
}