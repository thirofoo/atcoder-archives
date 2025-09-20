/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc424/submissions/69504940
 * Submitted at: 2025-09-20 22:36:47
 * Problem URL: https://atcoder.jp/contests/abc424/tasks/abc424_f
 * Result: AC
 * Execution Time: 191 ms
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

  ll n, q;
  cin >> n >> q;
  vector<ll> a(q), b(q);
  rep(i, q) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  segtree<S, op, e> seg_l(n), seg_r(n);

  rep(i, q) {
    ll l = a[i], r = b[i];
    ll max_r  = seg_l.prod(l + 1, r);
    ll max_nl = seg_r.prod(l + 1, r);
    if(max_r > r || max_nl > -l) cout << "No" << "\n";
    else {
      cout << "Yes" << "\n";
      seg_l.set(l, r);
      seg_r.set(r, -l);
    }
  }

  return 0;
}