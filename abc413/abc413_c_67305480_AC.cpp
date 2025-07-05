/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67305480
 * Submitted at: 2025-07-05 21:08:05
 * Problem URL: https://atcoder.jp/contests/abc413/tasks/abc413_c
 * Result: AC
 * Execution Time: 123 ms
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

  ll q;
  cin >> q;
  using P = pair<ll, ll>;
  deque<P> ps;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll c, x;
      cin >> c >> x;
      ps.emplace_back(c, x);
    } else {
      ll k;
      cin >> k;
      ll ans = 0;
      while(k > 0 && !ps.empty()) {
        auto [c, x] = ps.front();
        if(c <= k) {
          ans += c * x;
          k -= c;
          ps.pop_front();
        } else {
          ans += k * x;
          ps.front().first -= k;
          k = 0;
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}