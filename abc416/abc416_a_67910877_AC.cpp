/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc416/submissions/67910877
 * Submitted at: 2025-07-26 21:01:40
 * Problem URL: https://atcoder.jp/contests/abc416/tasks/abc416_a
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

  ll n, l, r;
  cin >> n >> l >> r;
  string s;
  cin >> s;
  l--;

  bool ok = true;
  for(ll i = l; i < r; i++) ok &= (s[i] == 'o');
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}