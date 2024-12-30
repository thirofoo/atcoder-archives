/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc067/submissions/61254766
 * Submitted at: 2024-12-30 22:41:38
 * Problem URL: https://atcoder.jp/contests/abc067/tasks/arc078_a
 * Result: AC
 * Execution Time: 13 ms
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
  ll ans = INF, sum = 0, total = 0;
  rep(i, n) {
    cin >> a[i];
    total += a[i];
  }
  rep(i, n - 1) {
    sum += a[i];
    ans = min(ans, abs(total - 2 * sum));
  }
  cout << ans << endl;

  return 0;
}