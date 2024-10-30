/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc376/submissions/59275265
 * Submitted at: 2024-10-30 19:38:19
 * Problem URL: https://atcoder.jp/contests/abc376/tasks/abc376_e
 * Result: AC
 * Execution Time: 242 ms
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

  ll t;
  cin >> t;
  while(t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<ll> perm(n);
    iota(perm.begin(), perm.end(), 0);
    sort(perm.begin(), perm.end(), [&](ll i, ll j) {
      return a[i] < a[j];
    });
    ll ans = INF, min_sum = 0;
    priority_queue<ll> pq;
    rep(i, k) {
      min_sum += b[perm[i]];
      pq.push(b[perm[i]]);
    }
    ans = a[perm[k - 1]] * min_sum;
    for(ll i = k; i < n; i++) {
      pq.push(b[perm[i]]);
      min_sum += b[perm[i]];
      min_sum -= pq.top();
      pq.pop();
      ans = min(ans, a[perm[i]] * min_sum);
    }
    cout << ans << endl;
  }

  return 0;
}