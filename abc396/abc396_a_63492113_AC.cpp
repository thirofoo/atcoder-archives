/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc396/submissions/63492113
 * Submitted at: 2025-03-08 21:00:51
 * Problem URL: https://atcoder.jp/contests/abc396/tasks/abc396_a
 * Result: AC
 * Execution Time: 2 ms
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

  bool ok = false;
  rep(i, n - 2) ok |= (a[i] == a[i + 1] && a[i + 1] == a[i + 2]);
  cout << (ok ? "Yes" : "No") << '\n';

  return 0;
}