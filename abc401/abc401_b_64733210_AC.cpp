/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc401/submissions/64733210
 * Submitted at: 2025-04-12 21:03:49
 * Problem URL: https://atcoder.jp/contests/abc401/tasks/abc401_b
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
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  bool login = false;
  ll ans     = 0;
  rep(i, n) {
    if(s[i] == "login") login = true;
    else if(s[i] == "logout") login = false;
    else ans += (s[i] == "private" && !login);
  }
  cout << ans << endl;

  return 0;
}