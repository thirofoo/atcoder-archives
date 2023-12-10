/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48410628
 * Submitted at: 2023-12-10 23:55:50
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_f
 * Result: AC
 * Execution Time: 273 ms
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

// S が data, F が lazy
using S = mint;
using F = struct {
    mint a, b;
};
// operator(作用素)
S op(S a,S b){
    return a+b;
}
// 遅延データ反映
S mapping(F f,S x){
    return f.a*x + f.b;
}
// 遅延データ作用
F composition(F f,F g){
    return F{g.a*f.a, f.a*g.b + f.b};
}
S e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return F{1,0}; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(n);
    rep(i,n) lsg.set(i, a[i]);
    rep(i,m) {
        ll l, r, x; cin >> l >> r >> x; l--;
        lsg.apply(l,r,F{(mint)(r-l-1)/(r-l), (mint)x/(r-l)});
    }
    rep(i,n) cout << lsg.get(i).val() << " ";
    cout << endl;
    
    return 0;
}