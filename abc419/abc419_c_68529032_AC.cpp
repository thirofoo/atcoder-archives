/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68529032
 * Submitted at: 2025-08-16 21:10:10
 * Problem URL: https://atcoder.jp/contests/abc419/tasks/abc419_c
 * Result: AC
 * Execution Time: 46 ms
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
  vector<ll> r(n), c(n);
  rep(i, n) cin >> r[i] >> c[i];
  sort(r.begin(), r.end());
  sort(c.begin(), c.end());
  cout << (max(r[n - 1] - r[0], c[n - 1] - c[0]) + 1) / 2 << endl;

  return 0;
}