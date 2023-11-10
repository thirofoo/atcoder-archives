/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/47417364
 * Submitted at: 2023-11-10 13:18:07
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_f
 * Result: AC
 * Execution Time: 31 ms
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
    
    ll n, m; string s; cin >> n >> m >> s;
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(n+1);
    lsg.set(0,0);
    rep(i,n) {
        if( s[i] == '1' ) continue;
        lsg.apply(i,min(n+1,i+m+1),lsg.get(i)+1);
    }
    rep(i,n+1) if( s[i] == '1' ) lsg.set(i,-1);
    if( lsg.get(n) == 1e9 ) return cout << -1 << endl, 0;

    int idx;
    stack<ll> st;
    for(int i=n; i>0;) {
        for(int j=max(i-m,0ll); j<i; j++) {
            if( lsg.get(j)+1 == lsg.get(i) ) {
                idx = j;
                break;
            }
        }
        st.push(i-idx);
        i = idx;
    }
    while( !st.empty() ) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}