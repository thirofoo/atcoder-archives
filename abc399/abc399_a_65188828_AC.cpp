/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/65188828
 * Submitted at: 2025-04-25 18:45:47
 * Problem URL: https://atcoder.jp/contests/abc399/tasks/abc399_a
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
  string s, t;
  cin >> n >> s >> t;
  ll ans = 0;
  rep(i, n) if(s[i] != t[i]) ans++;
  cout << ans << endl;

  return 0;
}