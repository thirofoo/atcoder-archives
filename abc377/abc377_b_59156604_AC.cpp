/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc377/submissions/59156604
 * Submitted at: 2024-10-26 21:04:04
 * Problem URL: https://atcoder.jp/contests/abc377/tasks/abc377_b
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
  
  ll n = 8;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<vector<bool>> ok(n, vector<bool>(n, true));
  rep(i, n) rep(j, n) {
    if(s[i][j] == '.') continue;
    rep(k, n) ok[i][k] = false;
    rep(k, n) ok[k][j] = false;
  }
  ll ans = 0;
  rep(i, n) rep(j, n) if(ok[i][j]) ans++;
  cout << ans << '\n';
  
  return 0;
}
