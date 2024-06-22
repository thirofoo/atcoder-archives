/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/54787704
 * Submitted at: 2024-06-22 19:49:38
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_e
 * Result: AC
 * Execution Time: 569 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// S:実 F:遅延
using S = struct {
    ll head, tail;
    bool ok;
};
using F = ll;
// operator (作用素)
S op(S l, S r) {
    if(l.head == -1) return r;
    if(r.head == -1) return l;
    return {l.head, r.tail, l.ok && r.ok && l.tail != r.head};
}
// 遅延データ反映
S mapping(F f, S x) {
    x.head ^= f;
    x.tail ^= f;
    return x;
}
// 遅延データ作用 ※ f(g(x))
F composition(F f, F g) {
   return f ^ g;
}
S e() { return {-1, -1, false}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // head, tail を管理すると、merge した後の区間における ok が判断出来る
    // ⇒ 遅延セグ木でも解ける
    
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i, n) seg.set(i, {s[i] - '0', s[i] - '0', true});
    while(q--) {
        ll t, l, r; cin >> t >> l >> r; l--;
        if(t == 1) seg.apply(l, r, 1);
        else cout << (seg.prod(l, r).ok ? "Yes" : "No") << endl;
    }
    
    return 0;
}