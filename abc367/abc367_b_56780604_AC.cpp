/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56780604
 * Submitted at: 2024-08-17 21:05:54
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_b
 * Result: AC
 * Execution Time: 1 ms
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
  
  string x; cin >> x;
  while(x.back() == '0') x.pop_back();
  if(x.back() == '.') x.pop_back();
  cout << x << '\n';
  
  return 0;
}