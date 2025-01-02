/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/61326361
 * Submitted at: 2025-01-03 01:32:17
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_g
 * Result: AC
 * Execution Time: 76 ms
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

using S = ll;
S op(S l, S r) {
  return max(l, r);
}
S e() {
  return -INF;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, c, m;
  cin >> n >> c >> m;
  segtree<S, op, e> lsg(n), rsg(n);
  lsg.set(0, -(n - 1) * c);
  rsg.set(0, 0);

  ll ans = 0;
  rep(i, m) {
    ll t, p;
    cin >> t >> p;
    ll best = lsg.prod(0, t) + (n - t) * c;
    if(t != n) best = max(best, rsg.prod(t, n) + (t - 1) * c);
    best += p;
    // cerr << best << endl;
    ans = max(ans, best);
    lsg.set(t - 1, best - (n - t) * c);
    rsg.set(t - 1, best - (t - 1) * c);
    // rep(j, n) cerr << lsg.get(j) << " ";
    // cerr << endl;
    // rep(j, n) cerr << rsg.get(j) << " ";
    // cerr << endl;
  }
  cout << ans << endl;

  return 0;
}