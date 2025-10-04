/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc426/submissions/69887181
 * Submitted at: 2025-10-05 01:52:46
 * Problem URL: https://atcoder.jp/contests/abc426/tasks/abc426_f
 * Result: AC
 * Execution Time: 542 ms
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

using S1 = ll;
S1 op1(S1 l, S1 r) {
  return l + r;
}
S1 e1() {
  return 0;
}

using S2 = ll;
using F  = ll;
S2 op2(S2 l, S2 r) {
  return min(l, r);
}
S2 mapping(F f, S2 x) {
  return x + f;
}
F composition(F f, F g) {
  return f + g;
}
S2 e2() {
  return INF;
}
F id() {
  return 0;
}
ll V = 0;
bool f(S2 a) {
  return a >= V;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  segtree<S1, op1, e1> sg1(n);
  lazy_segtree<S2, op2, e2, F, mapping, composition, id> sg2(n);
  rep(i, n) {
    sg1.set(i, 1);
    sg2.set(i, a[i]);
  }

  ll q;
  cin >> q;
  while(q--) {
    ll l, r, k;
    cin >> l >> r >> k;
    l--;
    ll ans = sg1.prod(l, r) * k;
    sg2.apply(l, r, -k);

    // rep(i, n) cerr << sg2.get(i) << " ";
    // cerr << "\n";

    while(sg2.prod(l, r) < 0) {
      ll idx = sg2.max_right<f>(l);
      if(idx >= r) break;
      // cerr << "idx: " << idx << "\n";
      ans += sg2.get(idx);
      sg2.set(idx, INF);
      sg1.set(idx, 0);
    }
    cout << ans << "\n";
  }

  return 0;
}