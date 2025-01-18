/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61828594
 * Submitted at: 2025-01-18 22:22:08
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_e
 * Result: WA
 * Execution Time: 1138 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  using ld = long double;
  ll n, m;
  cin >> n >> m;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  ll ans = 0, ans_total = 0;
  ll left = 0, right = INF;

  while(right - left > 1) {
    ll mid   = (left + right) / 2;
    ll total = 0, cand = 0;

    // cerr << "mid : " << mid << '\n';
    rep(i, n) {
      ll l2 = 0, r2 = 1000000005;
      while(r2 - l2 > 1) {
        ll m2         = (l2 + r2) / 2;
        __int128 lhs  = m2 * m2 * p[i];
        __int128 rhs  = (m2 + 1) * (m2 + 1) * p[i];
        __int128 diff = rhs - lhs;
        if(diff <= mid) l2 = m2;
        else r2 = m2;
      }
      __int128 v1   = l2 * l2 * p[i];
      __int128 v2   = (l2 + 1) * (l2 + 1) * p[i];
      __int128 diff = v2 - v1;
      if(diff > mid) continue;
      l2++;
      __int128 cost = (__int128) l2 * l2 * p[i];
      if(cost > INF) cost = INF;

      if(total > INF - (ll) cost) {
        total = INF;
        break;
      }
      total += (ll) cost;

      if(total > m) break;
      cand += l2;
      // cerr << i << " : " << l2 << '\n';
    }
    // cerr << '\n';

    if(total > m) {
      right = mid;
    } else {
      left = mid;
      if(cand > ans) {
        ans       = cand;
        ans_total = total;
      }
    }
  }

  ll rest = m - ans_total;
  // cerr << "left : " << left << '\n';
  // cerr << "rest : " << rest << '\n';
  ans += rest / (left + 1);
  cout << ans << '\n';

  return 0;
}
