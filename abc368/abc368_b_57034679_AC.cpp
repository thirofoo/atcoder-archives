/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc368/submissions/57034679
 * Submitted at: 2024-08-24 21:04:00
 * Problem URL: https://atcoder.jp/contests/abc368/tasks/abc368_b
 * Result: AC
 * Execution Time: 3 ms
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
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  ll time = 0;
  while(a[0] != 0 && a[1] != 0) {
    a[0]--;
    a[1]--;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    time++;
  }
  cout << time << '\n';

  return 0;
}