/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abl/submissions/49854385
 * Submitted at: 2024-02-01 12:57:01
 * Problem URL: https://atcoder.jp/contests/abl/tasks/abl_e
 * Result: AC
 * Execution Time: 583 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<mint> one;

using S = struct {
    ll len;
    mint sum;
};
using F = ll;
// operator(作用素)
S op(S a, S b){
    return S{a.len+b.len, a.sum*mint{10}.pow(b.len)+b.sum};
}
// 遅延データ反映
S mapping(F f,S x){
    if( f == 0 ) return x;
    return S{x.len, f*one[x.len-1]};
}
// 遅延データ作用
F composition(F f,F g){
    if( f == 0 ) return g;
    return f;
}
S e(){ return S{0,0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説 AC 
    // lazy_segtree 復習すべし

    ll n, q; cin >> n >> q;
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(n);
    rep(i,n) lsg.set(i, S{1,1});
    one.assign(n+1,1);
    rep(i,n) one[i+1] += one[i]*10;
    rep(i,q) {
        ll l, r, d; cin >> l >> r >> d;
        lsg.apply(l-1, r, d);
        cout << lsg.all_prod().sum.val() << endl;
    }
    
    return 0;
}