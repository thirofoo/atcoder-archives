/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc395/submissions/63239240
 * Submitted at: 2025-03-01 21:00:52
 * Problem URL: https://atcoder.jp/contests/abc395/tasks/abc395_a
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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  bool ok = true;
  rep(i, n - 1) ok &= (a[i] < a[i + 1]);
  cout << (ok ? "Yes" : "No") << '\n';

  return 0;
}