/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc414/submissions/67547925
 * Submitted at: 2025-07-12 22:06:41
 * Problem URL: https://atcoder.jp/contests/abc414/tasks/abc414_a
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

  ll n, l, r;
  cin >> n >> l >> r;
  ll ans = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if(x <= l && r <= y) ans++;
  }
  cout << ans << endl;

  return 0;
}