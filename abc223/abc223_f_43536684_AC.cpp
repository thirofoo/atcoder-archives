/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc223/submissions/43536684
 * Submitted at: 2023-07-13 23:21:57
 * Problem URL: https://atcoder.jp/contests/abc223/tasks/abc223_f
 * Result: AC
 * Execution Time: 88 ms
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

using S = P;
S op(S a,S b){
    // 累積和と累積和の最小値を乗せる。天才。
    // 累積和の最小値は、右の累積和は左の累積和を全て考慮する
    // → (左の累積和 + 右の累積和の最小値) の最小値が候補 !!
    return P( min(a.first, b.first + a.second) , a.second + b.second );
}

S e(){return P( INT_MAX,0 );} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説AC
    // segtreeは思いつくが、pairを持つのは初めて
    
    ll n,q; string s; input(n,q,s);
    segtree<S,op,e> sg(n);
    rep(i,n){
        if( s[i] == '(' )sg.set(i, P(1,1));
        else sg.set(i, P(-1,-1));
    }
    while(q--){
        ll t,l,r; input(t,l,r);
        l--; r--;
        if( t == 1 ){
            if( s[l] == '(' && s[r] == ')' ){
                sg.set(l,P(-1,-1));
                sg.set(r,P(1,1));
            }
            else if( s[l] == ')' && s[r] == '(' ){
                sg.set(l,P(1,1));
                sg.set(r,P(-1,-1));
            }
            swap(s[l],s[r]);
        }
        else{
            if( sg.prod(l,r+1) == P(0,0) ) print("Yes");
            else print("No");
        }
    }
    
    return 0;
}