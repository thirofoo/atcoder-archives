/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc415/submissions/67702185
 * Submitted at: 2025-07-19 21:00:40
 * Problem URL: https://atcoder.jp/contests/abc415/tasks/abc415_a
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
  ll x;
  cin >> x;
  bool ok = false;
  rep(i, n) ok |= (a[i] == x);
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}