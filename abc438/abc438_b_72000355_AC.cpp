/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc438/submissions/72000355
 * Submitted at: 2025-12-27 21:06:06
 * Problem URL: https://atcoder.jp/contests/abc438/tasks/abc438_b
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

  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  ll ans = INF;
  rep(i, n - m + 1) {
    ll tmp = 0;
    rep(j, m) tmp += ((s[i + j] - '0') - (t[j] - '0') + 10) % 10;
    ans = min(ans, tmp);
  }
  cout << ans << "\n";

  return 0;
}