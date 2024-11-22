/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60042903
 * Submitted at: 2024-11-22 21:08:35
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_c
 * Result: AC
 * Execution Time: 4 ms
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
  vector<ll> one(n, 0), two(n, 0);
  rep(i, n - 1) {
    one[i + 1] = one[i] + (s[i] == '1');
    if(s[i] != '1') one[i + 1] = 0;
  }
  for(ll i = n - 1; i >= 1; i--) {
    two[i - 1] = two[i] + (s[i] == '2');
    if(s[i] != '2') two[i - 1] = 0;
  }
  ll ans = 0;
  rep(i, n) {
    if(s[i] != '/') continue;
    ans = max(ans, 2 * min(one[i], two[i]) + 1);
  }
  cout << ans << '\n';

  return 0;
}