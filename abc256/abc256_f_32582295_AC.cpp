/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32582295
 * Submitted at: 2022-06-19 11:58:22
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_f
 * Result: AC
 * Execution Time: 491 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

mint op(mint a,mint b){
    return a+b;
}
 
mint e(){
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    segtree<mint,op,e> sg1(n+1),sg2(n+1),sg3(n+1);
    rep(i,n){
        int a; cin >> a;
        sg1.set(i+1,(mint)a);
        sg2.set(i+1,(mint)a*(i+1));
        sg3.set(i+1,(mint)a*(i+1)*(i+1));
    }

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x,v; cin >> x >> v;
            sg1.set(x,(mint)v);
            sg2.set(x,(mint)v*x);
            sg3.set(x,(mint)v*x*x);
        }
        else{
           ll x; cin >> x;
            cout << (sg3.prod(0,x+1)/2 - (2*x+3)*sg2.prod(0,x+1)/2 + (x+1)*(x+2)*sg1.prod(0,x+1)/2).val() << endl;
        }
    }

    return 0;
}