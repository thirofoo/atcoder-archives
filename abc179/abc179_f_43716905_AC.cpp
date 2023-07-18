/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/43716905
 * Submitted at: 2023-07-18 15:42:33
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_f
 * Result: AC
 * Execution Time: 140 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = int;
using F = int;
// operator(作用素)
S op(S a,S b){
    return min(a,b);
}
// 遅延データ反映
S mapping(F f,S x){
    return min(f,x);
}
// 遅延データ作用
F composition(F f,F g){
    return min(f,g);
}
S e(){ return 1e9; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 1e9; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    lazy_segtree<S,op,e,F,mapping,composition,id> row(n), column(n);
    rep(i,n){
        row.set(i,n-1);
        column.set(i,n-1);
    }
    ll ans = (n-2)*(n-2);
    while(q--) {
        ll t,x; cin >> t >> x; x--;
        if( t == 1 ){
            ans -= column.get(x) - 1;
            row.apply( 0, column.get(x), x );
        }
        else{
            ans -= row.get(x) - 1;
            column.apply( 0, row.get(x), x );
        }
    }
    cout << ans << endl;
    
    return 0;
}