/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66114830
 * Submitted at: 2025-05-24 21:43:36
 * Problem URL: https://atcoder.jp/contests/abc407/tasks/abc407_e
 * Result: AC
 * Execution Time: 43 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using P   = pair<ll, ll>;
using T   = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;

  while(t--) {
    ll n;
    cin >> n;
    ll m = 2 * n;
    vector<ll> a(m);
    ll total_sum = 0;
    rep(i, m) {
      cin >> a[i];
      total_sum += a[i];
    }
    priority_queue<ll> pq;
    ll lost_sum = 0;
    rep(i, m) {
      pq.push(a[i]);
      lost_sum += a[i];
      ll limit = (i + 1) / 2;
      if((ll) pq.size() > limit) {
        lost_sum -= pq.top();
        pq.pop();
      }
    }
    cout << total_sum - lost_sum << '\n';
  }

  return 0;
}
