/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68550098
 * Submitted at: 2025-08-16 21:35:33
 * Problem URL: https://atcoder.jp/contests/abc419/tasks/abc419_e
 * Result: AC
 * Execution Time: 362 ms
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

  ll n, m, l;
  cin >> n >> m >> l;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  // i % l が一致する場所の mod m は一致しそう

  rep(i, n) a[i] %= m;
  vector<vector<ll>> cls(l);
  rep(i, n) cls[i % l].emplace_back(a[i]);

  vector<vector<ll>> cost(l, vector<ll>(m, 0));
  rep(j, l) {
    sort(cls[j].begin(), cls[j].end());
    ll sum_a = 0;
    rep(t, cls[j].size()) sum_a += cls[j][t];
    rep(x, m) {
      ll idx     = upper_bound(cls[j].begin(), cls[j].end(), x) - cls[j].begin();
      cost[j][x] = cls[j].size() * x - sum_a + (cls[j].size() - idx) * m;
    }
  }

  vector<ll> dp(m, INF), ndp;
  dp[0] = 0;
  rep(j, l) {
    ndp.assign(m, INF);
    rep(r, m) {
      ll dr = dp[r];
      if(dr >= INF) continue;
      rep(x, m) {
        ll r2 = (r + x) % m;
        if(dr + cost[j][x] < ndp[r2]) ndp[r2] = dr + cost[j][x];
      }
    }
    dp.swap(ndp);
  }

  ll ans = dp[0];
  cout << ans << endl;

  return 0;
}
