/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/59562469
 * Submitted at: 2024-11-09 21:01:12
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_a
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

  string s;
  cin >> s;
  cout << s[1] << s[2] << s[0] << " ";
  cout << s[2] << s[0] << s[1] << endl;

  return 0;
}