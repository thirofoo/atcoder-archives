/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69491314
 * Submitted at: 2025-09-20 21:58:33
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_d
 * Result: AC
 * Execution Time: 12 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--) {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<ll> r(h, 0);
    ll total = 0;
    rep(i, h) rep(j, w) {
      if(s[i][j] == '#') {
        r[i] |= 1LL << j;
        total++;
      }
    }

    ll lim = (1LL << w);
    vector<ll> dp(lim, -INF), ndp(lim, -INF);
    rep(m, lim) if((m & ~r[0]) == 0) dp[m] = __builtin_popcountll(m);

    for(ll i = 1; i < h; i++) {
      ndp.assign(lim, -INF);
      rep(pm, lim) {
        if(dp[pm] < 0) continue;
        rep(cm, lim) {
          if((cm & ~r[i]) != 0) continue;
          if((pm & (pm << 1) & cm & (cm << 1)) == 0) {
            ndp[cm] = max(ndp[cm], dp[pm] + (ll) __builtin_popcountll(cm));
          }
        }
      }
      dp.swap(ndp);
    }

    ll keep          = 0;
    rep(m, lim) keep = max(keep, dp[m]);
    cout << (total - keep) << "\n";
  }

  return 0;
}
