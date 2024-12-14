/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60718337
 * Submitted at: 2024-12-14 21:01:13
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_a
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
  char c1, c2;
  cin >> n >> c1 >> c2;
  string s;
  cin >> s;
  rep(i, n) {
    if(s[i] != c1) cout << c2;
    else cout << s[i];
  }
  cout << '\n';

  return 0;
}