/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60723523
 * Submitted at: 2024-12-14 21:03:39
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_b
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

  ll n, r;
  cin >> n >> r;
  vector<ll> d(n), a(n);
  rep(i, n) {
    cin >> d[i] >> a[i];
    if(d[i] == 1 && 1600 <= r && r < 2800) r += a[i];
    if(d[i] == 2 && 1200 <= r && r < 2400) r += a[i];
  }
  cout << r << '\n';

  return 0;
}
