/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc373/submissions/58189219
 * Submitted at: 2024-09-28 21:06:03
 * Problem URL: https://atcoder.jp/contests/abc373/tasks/abc373_c
 * Result: AC
 * Execution Time: 65 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  ll max_a = -INF, max_b = -INF;
  rep(i, n) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }
  rep(i, n) {
    cin >> b[i];
    max_b = max(max_b, b[i]);
  }
  cout << max_a + max_b << endl;
  
  return 0;
}