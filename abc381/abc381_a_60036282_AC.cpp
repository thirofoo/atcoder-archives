/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc381/submissions/60036282
 * Submitted at: 2024-11-22 21:01:57
 * Problem URL: https://atcoder.jp/contests/abc381/tasks/abc381_a
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

  if(n % 2 == 0) {
    return cout << "No" << '\n', 0;
  }

  bool flag = true;
  rep(i, n / 2) flag &= (s[i] == '1');
  reverse(s.begin(), s.end());
  rep(i, n / 2) flag &= (s[i] == '2');
  flag &= (s[n / 2] == '/');
  cout << (flag ? "Yes" : "No") << '\n';

  return 0;
}