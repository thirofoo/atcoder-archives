/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc394/submissions/62993497
 * Submitted at: 2025-02-22 21:01:05
 * Problem URL: https://atcoder.jp/contests/abc394/tasks/abc394_a
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
  rep(i, s.size()) if(s[i] == '2') ans += '2';
  cout << ans << '\n';

  return 0;
}