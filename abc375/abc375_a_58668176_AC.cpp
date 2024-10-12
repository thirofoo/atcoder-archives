/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc375/submissions/58668176
 * Submitted at: 2024-10-12 21:01:06
 * Problem URL: https://atcoder.jp/contests/abc375/tasks/abc375_a
 * Result: AC
 * Execution Time: 3 ms
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
  
  ll n;
  string s;
  cin >> n >> s;
  ll ans = 0;
  rep(i, n-2) {
    if(s[i] == '#' && s[i+1] == '.' && s[i+2] == '#') ans++;
  }
  cout << ans << '\n';
  
  return 0;
}