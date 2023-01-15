/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38076189
 * Submitted at: 2023-01-15 22:39:49
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_f
 * Result: RE
 * Execution Time: 119 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = ll;
using F = ll;
// operator(作用素)
S op(S a,S b){
    return a+b;
}
// 遅延データ反映
S mapping(F f,S x){
    return f+x;
}
// 遅延データ作用
F composition(F f,F g){
    return f+g;
}
S e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; string s; input(n,s,q);
    vector<ll> a(n),b(n,1);
    rep(i,n)a[i] = s[i]-'a';

    set<ll> st;
    st.insert(0);
    for(ll i=1;i<n;i++){
        if(a[i-1] <= a[i])b[i] = b[i-1]+1;
        else st.insert(i+1);
    }

    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(b);
    
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll x; char c; input(x,c); x--;
            if(a[x] == c-'a')continue;
            else if(a[x] < c-'a'){
                if(x == n-1 || lsg.get(x) == 1)continue;
                if(a[x+1] < c){
                    auto itr = st.upper_bound(x);
                    lsg.apply(x+1,*itr,lsg.get(x));
                }
            }
            else{
                if(x == 0 || lsg.get(x) == 1)continue;
                if(c-'a' < a[x-1]){
                    auto itr = st.upper_bound(x-1);
                    lsg.apply(x,*itr,-lsg.get(x-1));
                }
            }
        }
        else{
            ll l,r; input(l,r);
            l--; r--;
            if(lsg.get(r)-lsg.get(l) == r-l)print("Yes");
            else print("No");
        }
    }
    
    return 0;
}