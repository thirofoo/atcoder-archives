/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57030402
 * Submitted at: 2024-08-24 21:01:42
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_a
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

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll time = 0;
  while(time < n) {
    cout << a[(n - k + time) % n] << " ";
    time++;
  }
  cout << '\n';

  return 0;
}