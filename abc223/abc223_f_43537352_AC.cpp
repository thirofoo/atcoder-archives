/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/43537352
 * Submitted at: 2023-07-13 23:51:10
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_f
 * Result: AC
 * Execution Time: 148 ms
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


using S = ll;
using F = ll;

S op(S a,S b){
    return min(a,b);
}
// 遅延データ反映
S mapping(F f,S x){
    return f+x;
}
// 遅延データ作用
F composition(F f,F g){
    return f+g;
}
S e(){ return INT_MAX; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説AC
    // 勿論 LazySegTree でも可
    
    ll n,q; string s; input(n,q,s);
    vector<ll> base(n+1,0);
    rep(i,n){
        if( s[i] == '(' )base[i+1]++;
        else base[i+1]--;
    }
    rep(i,n) base[i+1] += base[i];
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(base);
    while(q--){
        ll t,l,r; input(t,l,r);
        if( t == 1 ){
            if( s[l-1] == '(' && s[r-1] == ')' ){
                // 元々の () が )( になる → その区間だけ -2 累積和がになる
                lsg.apply( l,r,-2 );
            }
            else if( s[l-1] == ')' && s[r-1] == '(' ){
                lsg.apply( l,r,2 );
            }
            swap(s[l-1],s[r-1]);
        }
        else{
            // 遅延評価SegmentTreeの場合ここが注意！
            // lsga.prod(l,r+1) == 0 はダメ。
            // 累積和は前の影響を受けている事に着目
            // → 過去の累積和 = 区間の累積和最小値 なら OK !!
            if( lsg.prod(l,r+1) - lsg.get(l-1) == 0 && lsg.get(r) == lsg.get(l-1) ) print("Yes");
            else print("No");
        }
    }
    
    return 0;
}