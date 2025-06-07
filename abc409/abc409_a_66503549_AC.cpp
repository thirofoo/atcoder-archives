/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66503549
 * Submitted at: 2025-06-07 21:01:01
 * Problem URL: https://atcoder.jp/contests/abc409/tasks/abc409_a
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
  string t, a;
  cin >> n >> t >> a;
  bool ok = false;
  rep(i, n) ok |= (t[i] == 'o' && a[i] == 'o');
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}