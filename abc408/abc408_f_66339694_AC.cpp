/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66339694
 * Submitted at: 2025-05-31 21:43:59
 * Problem URL: https://atcoder.jp/contests/abc408/tasks/abc408_f
 * Result: AC
 * Execution Time: 133 ms
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

using S = ll;
S op(S l, S r) {
  return l > r ? l : r;
}
S e() {
  return -1LL;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, d, r;
  cin >> n >> d >> r;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];

  vector<P> by_height(n);
  rep(i, n) by_height[i] = {h[i], i};
  sort(by_height.begin(), by_height.end());

  vector<ll> dp(n, 0);
  segtree<ll, op, e> seg(n);
  ll add_ptr = 0;

  rep(k, n) {
    auto [cur_h, idx] = by_height[k];
    while(add_ptr < k && by_height[add_ptr].first <= cur_h - d) {
      ll j = by_height[add_ptr].second;
      seg.set(j, dp[j]);
      add_ptr++;
    }
    ll l    = max(0LL, idx - r);
    ll rr   = min(n - 1, idx + r);
    ll best = seg.prod(l, rr + 1);
    dp[idx] = best == -1 ? 0 : best + 1;
  }

  ll ans        = 0;
  rep(i, n) ans = max(ans, dp[i]);
  cout << ans << endl;

  return 0;
}
