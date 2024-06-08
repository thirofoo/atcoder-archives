/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54376020
 * Submitted at: 2024-06-08 22:36:27
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_f
 * Result: WA
 * Execution Time: 5637 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// S:実 F:遅延
using S = struct {
  ll a_sum;
  ll b_sum;
  mint ans_sum;
  ll size;
};
using F = P;
// operator (作用素)
S op(S l, S r) {
    S res;
    res.a_sum = l.a_sum + r.a_sum;
    res.b_sum = l.b_sum + r.b_sum;
    res.ans_sum = l.ans_sum + r.ans_sum;
    res.size = l.size + r.size;
    return res;
}
// 遅延データ反映
S mapping(F f,S x) {
    auto [a, b] = f;
    S res;
    res.a_sum = x.a_sum + a*x.size;
    res.b_sum = x.b_sum + b*x.size;
    res.ans_sum = x.ans_sum + b*x.a_sum + a*x.b_sum + a*b*x.size;
    res.size = x.size;
    return res;
}
// 遅延データ作用 ※ f(g(x))
F composition(F f, F g) {
    auto [a1, b1] = f;
    auto [a2, b2] = g;
    return {a1 + a2, b1 + b2};
}
S e() { return {0, 0, 0, 0}; } // 単位元
F id() { return {0, 0}; } // 恒等写像

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i,n) seg.set(i, {a[i], b[i], a[i]*b[i], 1});
    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll l, r, x; cin >> l >> r >> x;
            seg.apply(l-1, r, {x, 0});
        }
        else if(t == 2) {
            ll l, r, x; cin >> l >> r >> x;
            seg.apply(l-1, r, {0, x});
        }
        else {
            ll l, r; cin >> l >> r;
            cout << seg.prod(l-1, r).ans_sum.val() << endl;
        }
        rep(i,n) cerr << seg.prod(i, i+1).a_sum << " ";
        cerr << endl;
        rep(i,n) cerr << seg.prod(i, i+1).b_sum << " ";
        cerr << endl;
        rep(i,n) cerr << seg.prod(i, i+1).ans_sum.val() << " ";
        cerr << endl;
        cerr << endl;
    }
    
    return 0;
}