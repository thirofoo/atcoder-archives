/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc094/submissions/61353564
 * Submitted at: 2025-01-04 14:46:55
 * Problem URL: https://atcoder.jp/contests/arc094/tasks/arc094_c
 * Result: WA
 * Execution Time: 4 ms
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
  vector<ll> a(n), b(n);
  ll min_b = INF;
  rep(i, n) {
    cin >> a[i] >> b[i];
    if(a[i] > b[i]) min_b = min(min_b, b[i]);
  }
  if(a == b) return cout << 0 << endl, 0;
  ll ans = accumulate(a.begin(), a.end(), 0) - min_b;
  cout << ans << endl;

  return 0;
}