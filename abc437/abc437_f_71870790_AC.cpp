/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc437/submissions/71870790
 * Submitted at: 2025-12-20 22:19:43
 * Problem URL: https://atcoder.jp/contests/abc437/tasks/abc437_f
 * Result: AC
 * Execution Time: 243 ms
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
S max_op(S l, S r) {
  return max(l, r);
}
S max_e() {
  return -INF;
}
S min_op(S l, S r) {
  return min(l, r);
}
S min_e() {
  return INF;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, q;
  cin >> n >> q;
  vector<ll> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  // 45 度回転
  segtree<S, max_op, max_e> seg_u_max(n), seg_v_max(n);
  segtree<S, min_op, min_e> seg_u_min(n), seg_v_min(n);
  vector<ll> u(n), v(n);
  rep(i, n) {
    u[i] = x[i] + y[i];
    v[i] = x[i] - y[i];
    seg_u_max.set(i, u[i]);
    seg_v_max.set(i, v[i]);
    seg_u_min.set(i, u[i]);
    seg_v_min.set(i, v[i]);
  }

  rep(i, q) {
    ll t;
    cin >> t;
    if(t == 1) {
      ll idx, nx, ny;
      cin >> idx >> nx >> ny;
      idx--;
      u[idx] = nx + ny;
      v[idx] = nx - ny;
      seg_u_max.set(idx, u[idx]);
      seg_v_max.set(idx, v[idx]);
      seg_u_min.set(idx, u[idx]);
      seg_v_min.set(idx, v[idx]);
    } else {
      ll l, r, nx, ny;
      cin >> l >> r >> nx >> ny;
      l--;
      ll u_q = nx + ny, v_q = nx - ny;
      ll ans = -INF;
      ans    = max(ans, seg_u_max.prod(l, r) - u_q);
      ans    = max(ans, u_q - seg_u_min.prod(l, r));
      ans    = max(ans, seg_v_max.prod(l, r) - v_q);
      ans    = max(ans, v_q - seg_v_min.prod(l, r));
      cout << ans << "\n";
    }
  }

  return 0;
}