/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc372/submissions/66898320
 * Submitted at: 2025-06-20 16:37:44
 * Problem URL: https://atcoder.jp/contests/abc372/tasks/abc372_a
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
  string ans = "";
  for(char c: s) {
    if(c == '.') continue;
    ans += c;
  }
  cout << ans << endl;

  return 0;
}