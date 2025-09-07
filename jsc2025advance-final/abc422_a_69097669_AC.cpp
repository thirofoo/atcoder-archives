/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/jsc2025advance-final/submissions/69097669
 * Submitted at: 2025-09-07 13:11:52
 * Problem URL: https://atcoder.jp/contests/jsc2025advance-final/tasks/abc422_a
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
  ll s1 = s[0] - '0', s2 = s[2] - '0';
  s2++;
  if(s2 == 9) {
    s2 = 1;
    s1++;
  }
  cout << s1 << "-" << s2 << endl;

  return 0;
}