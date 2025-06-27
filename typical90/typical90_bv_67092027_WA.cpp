/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/67092027
 * Submitted at: 2025-06-27 12:47:13
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bv
 * Result: WA
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
  ll ans = 0;
  rep(i, n) {
    if(s[i] == 'a') continue;
    else if(s[i] == 'b') ans += pow(2, i);
    else if(s[i] == 'c') ans += 2 * pow(2, i);
  }
  cout << ans << endl;

  return 0;
}
