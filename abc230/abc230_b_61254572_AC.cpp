/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/61254572
 * Submitted at: 2024-12-30 22:34:46
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_b
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
  bool ok1 = true, ok2 = true, ok3 = true;
  rep(i, s.size()) {
    ok1 &= (i % 3 == 0 && s[i] == 'o') || (i % 3 != 0 && s[i] == 'x');
    ok2 &= (i % 3 == 1 && s[i] == 'o') || (i % 3 != 1 && s[i] == 'x');
    ok3 &= (i % 3 == 2 && s[i] == 'o') || (i % 3 != 2 && s[i] == 'x');
  }
  cout << (ok1 || ok2 || ok3 ? "Yes" : "No") << endl;

  return 0;
}