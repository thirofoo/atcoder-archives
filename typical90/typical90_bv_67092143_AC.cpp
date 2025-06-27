/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67092143
 * Submitted at: 2025-06-27 12:55:55
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bv
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
  string s;
  cin >> n >> s;
  ll ans = 0, r = 1;
  rep(i, n) {
    if(s[i] == 'b') ans += r;
    else if(s[i] == 'c') ans += 2 * r;
    r *= 2;
  }
  cout << ans << endl;

  return 0;
}
