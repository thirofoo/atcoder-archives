/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41923453
 * Submitted at: 2023-06-03 13:45:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bp
 * Result: AC
 * Execution Time: 56 ms
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

//セグ木状に乗せる型。
using S = ll;
S op(S a,S b){return a+b;} // operator(作用素)
S e(){return 0;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; input(n,q);
    // 交代和が O(logN) で取れれば行けそう…？
    // → SegmentTree?
    // sg1 : iが偶数番目 , sg2 : iが奇数番目
    // sg[i] : a[i] + a[i+1]
    segtree<S,op,e> sg1(n-1),sg2(n-1);
    dsu uf(n);

    while(q--){
        ll t,x,y,v; input(t,x,y,v);
        x--; y--;
        if(t == 0){
            if(x%2 == 0)sg1.set(x,v);
            else sg2.set(x,v);
            uf.merge(x,y);
        }
        else{
            if(uf.same(x,y)){
                ll w = sg1.prod(min(x,y),max(x,y)) - sg2.prod(min(x,y),max(x,y));
                if(x < y){
                    if(x%2 == 0 && y%2 == 0)print(-w+v);
                    else if(x%2 == 1 && y%2 == 0)print(-w-v);
                    else if(x%2 == 0 && y%2 == 1)print(w-v);
                    else print(w+v);
                }
                else{
                    if(x%2 == 0 && y%2 == 0)print(w+v);
                    else if(x%2 == 1 && y%2 == 0)print(w-v);
                    else if(x%2 == 0 && y%2 == 1)print(-w-v);
                    else print(-w+v);
                }
            }
            else print("Ambiguous");
        }
    }
    
    return 0;
}