/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66301672
 * Submitted at: 2025-05-31 21:04:29
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_a
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

  ll n, s;
  cin >> n >> s;
  vector<ll> t(n + 1, 0);
  rep(i, n) cin >> t[i + 1];
  bool ok = true;
  rep(i, n) ok &= abs(t[i] - t[i + 1]) <= s;
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}