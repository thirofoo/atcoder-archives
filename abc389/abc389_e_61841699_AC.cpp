/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc389/submissions/61841699
 * Submitted at: 2025-01-19 00:07:54
 * Problem URL: https://atcoder.jp/contests/abc389/tasks/abc389_e
 * Result: AC
 * Execution Time: 49 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> p(n);
  rep(i, n) cin >> p[i];

  ll ans = 0, ans_total = 0;
  ll left = 0, right = INF;

  while(right - left > 1) {
    ll mid   = (left + right) / 2;
    ll total = 0, cand = 0;

    rep(i, n) {
      ll cnt        = ((long double) mid / p[i] + 1) / 2;
      __int128 cost = (__int128) cnt * cnt * p[i];
      if(cost > INF) cost = INF;
      if(total > INF - (ll) cost) {
        total = INF;
        break;
      }
      total += (ll) cost;
      if(total > m) break;
      cand += cnt;
    }

    if(total > m) right = mid;
    else {
      left = mid;
      if(cand > ans) {
        ans       = cand;
        ans_total = total;
      }
    }
  }

  ll rest = m - ans_total;
  ans += rest / (left + 1);
  cout << ans << '\n';

  return 0;
}
