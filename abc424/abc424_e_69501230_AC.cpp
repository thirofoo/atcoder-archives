/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69501230
 * Submitted at: 2025-09-20 22:26:23
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_e
 * Result: AC
 * Execution Time: 282 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(15);

  ll t;
  cin >> t;
  using P = pair<ld, ll>;

  while(t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    priority_queue<P> pq;
    ll total = 0;
    rep(i, n) pq.push({a[i], 1});

    while(true) {
      auto [val, cnt] = pq.top();
      pq.pop();
      if(total + cnt > k) {
        pq.push({val / 2, (k - total) * 2});
        pq.push({val, total + cnt - k});
        break;
      }
      total += cnt;
      pq.push({val / 2, cnt * 2});
    }

    ll now = 0;
    while(!pq.empty()) {
      auto [val, cnt] = pq.top();
      // cerr << val << " " << cnt << "\n";
      pq.pop();
      if(now + cnt >= x) {
        cout << val << "\n";
        break;
      }
      now += cnt;
    }
  }

  return 0;
}