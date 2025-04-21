/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/65083859
 * Submitted at: 2025-04-21 19:34:49
 * Problem URL: https://atcoder.jp/contests/abc397/tasks/abc397_b
 * Result: AC
 * Execution Time: 2 ms
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
  ll ans = 0;
  rep(i, s.size() - 1) ans += (s[i] == s[i + 1]);
  ans += (s.back() == 'i');
  ans += (s[0] == 'o');
  cout << ans << endl;

  return 0;
}