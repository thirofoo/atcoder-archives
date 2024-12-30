/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc379/submissions/61254914
 * Submitted at: 2024-12-30 22:48:01
 * Problem URL: https://atcoder.jp/contests/abc379/tasks/abc379_d
 * Result: AC
 * Execution Time: 193 ms
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
  deque<ll> dq;
  ll now = 0;
  while(q--) {
    ll t;
    cin >> t;
    if(t == 1) {
      dq.push_back(now);
    } else if(t == 2) {
      ll T;
      cin >> T;
      now += T;
    } else {
      ll H;
      cin >> H;
      ll ans = 0;
      while(!dq.empty() && abs((ll) dq.front() - now) >= H) {
        dq.pop_front();
        ans++;
      }
      cout << ans << endl;
    }
  }

  return 0;
}