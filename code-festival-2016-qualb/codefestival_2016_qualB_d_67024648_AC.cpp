/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/code-festival-2016-qualb/submissions/67024648
 * Submitted at: 2025-06-23 19:42:53
 * Problem URL: https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_d
 * Result: AC
 * Execution Time: 18 ms
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

  ll ans = a[0] - 1, threshold = 2;
  for(ll i = 1; i < n; i++) {
    if(a[i] == threshold) threshold++;
    else ans += (a[i] - 1) / threshold;
  }
  cout << ans << endl;

  return 0;
}