/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63246010
 * Submitted at: 2025-03-01 21:03:52
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_b
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

  ll n;
  cin >> n;

  vector<string> s(n, "");
  rep(i, n) rep(j, n) s[i] += '.';

  for(ll i = 0; n - i > i; i += 2) {
    for(ll j = i; j < n - i; j++) {
      s[i][j]         = '#';
      s[j][i]         = '#';
      s[n - i - 1][j] = '#';
      s[j][n - i - 1] = '#';
    }
  }
  rep(i, n) cout << s[i] << '\n';

  return 0;
}