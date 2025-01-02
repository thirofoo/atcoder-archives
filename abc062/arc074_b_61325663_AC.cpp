/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc062/submissions/61325663
 * Submitted at: 2025-01-03 00:47:16
 * Problem URL: https://atcoder.jp/contests/abc062/tasks/arc074_b
 * Result: AC
 * Execution Time: 41 ms
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
  vector<ll> a(3 * n);
  rep(i, 3 * n) cin >> a[i];
  priority_queue<ll, vector<ll>, greater<ll>> pq1;
  priority_queue<ll> pq2;
  vector<ll> top_sum_big(3 * n + 1, -INF), top_sum_small(3 * n + 1, INF);
  ll sum = 0;
  rep(i, n) {
    pq1.push(a[i]);
    sum += a[i];
  }
  for(ll i = n; i <= 2 * n; i++) {
    top_sum_big[i] = sum;
    pq1.push(a[i]);
    sum += a[i];
    sum -= pq1.top();
    pq1.pop();
  }
  sum = 0;
  for(ll i = 3 * n - 1; i >= 2 * n; i--) {
    pq2.push(a[i]);
    sum += a[i];
  }
  for(ll i = 2 * n - 1; i >= n - 1; i--) {
    top_sum_small[i + 1] = sum;
    pq2.push(a[i]);
    sum += a[i];
    sum -= pq2.top();
    pq2.pop();
  }
  ll ans                = -INF;
  rep(i, 3 * n + 1) ans = max(ans, top_sum_big[i] - top_sum_small[i]);
  // rep(i, 3 * n + 1) cerr << top_sum_big[i] << " ";
  // cerr << endl;
  // rep(i, 3 * n + 1) cerr << top_sum_small[i] << " ";
  // cerr << endl;
  cout << ans << endl;

  return 0;
}