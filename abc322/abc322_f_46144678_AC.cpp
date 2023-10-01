/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46144678
 * Submitted at: 2023-10-01 22:27:30
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_f
 * Result: AC
 * Execution Time: 394 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct Data {
    ll l0;
    ll l1;
    ll r0;
    ll r1;
    ll ans0;
    ll ans1;
    ll len;
};

// S が data, F が lazy
using S = Data;
using F = ll;
// operator(作用素)
S op(S a,S b){
    Data res;
    res.l0 = a.l0 + (a.l0 == a.len ? b.l0 : 0);
    res.r0 = b.r0 + (b.r0 == b.len ? a.r0 : 0);
    res.l1 = a.l1 + (a.l1 == a.len ? b.l1 : 0);
    res.r1 = b.r1 + (b.r1 == b.len ? a.r1 : 0);
    res.ans0 = max({a.ans0, b.ans0, res.l0, res.r0, a.r0 + b.l0});
    res.ans1 = max({a.ans1, b.ans1, res.l1, res.r1, a.r1 + b.l1});
    res.len = a.len + b.len;
    return res;
}
// 遅延データ反映
S mapping(F f,S x){
    if( f ) {
        swap(x.l0, x.l1);
        swap(x.r0, x.r1);
        swap(x.ans0, x.ans1);
    }
    return x;
}
// 遅延データ作用
F composition(F f,F g){ return f^g; }
S e(){ return {0, 0, 0, 0, 0, 0, 0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; string s; cin >> n >> q >> s;
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(n);
    rep(i,n) {
        ll tmp = s[i]-'0';
        lsg.set(i, { !tmp, tmp, !tmp, tmp, !tmp, tmp, 1 });
    }
    while( q-- ) {
        ll c, l, r; cin >> c >> l >> r; l--;
        if( c == 1 ) lsg.apply(l,r,1);
        else cout << lsg.prod(l,r).ans1 << endl;
        // rep(i,n) cerr << lsg.get(i).ans1 << " ";
        // cerr << endl;
    }
    
    return 0;
}