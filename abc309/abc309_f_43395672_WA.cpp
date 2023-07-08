/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43395672
 * Submitted at: 2023-07-08 23:48:25
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_f
 * Result: WA
 * Execution Time: 252 ms
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

S op(S a,S b){return max(a,b);} // operator(作用素)
S e(){return -1;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);

    vector<T> tyoku;
    // 座標圧縮
    vector<ll> comp;
    rep(i,n){
        ll h,w,d; input(h,w,d);
        vector<ll> tmp;
        tmp.push_back(h);
        tmp.push_back(w);
        tmp.push_back(d);
        sort(tmp.begin(), tmp.end());
        h = tmp[2];
        w = tmp[1];
        d = tmp[0];

        tyoku.push_back(T(h,w,d));
        comp.push_back(h);
        comp.push_back(w);
        comp.push_back(d);
    }
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    
    rep(i,n){
        auto [h,w,d] = tyoku[i];
        h = lower_bound(comp.begin(),comp.end(),h)-comp.begin();
        w = lower_bound(comp.begin(),comp.end(),w)-comp.begin();
        d = lower_bound(comp.begin(),comp.end(),d)-comp.begin();
        tyoku[i] = T(h,w,d);
    }
    sort(tyoku.begin(), tyoku.end());
    reverse(tyoku.begin(), tyoku.end());

    segtree<S,op,e> sg(600005);
    bool f = false;
    auto [hh, __, _] = tyoku[0];
    ll pre = hh;
    queue<P> todo;

    rep(i,n){
        auto [h,w,d] = tyoku[i];

        todo.push(P(w,d));
        if( pre != h ){
            while(!todo.empty()){
                auto [ww,dd] = todo.front(); todo.pop();
                sg.set(ww,max(sg.get(ww),dd));
            }
        }

        if( sg.prod(w+1,600005) > d ){
            f = true;
            break;
        }
        pre = h;
    }
    print( (f ? "Yes" : "No") );
    
    return 0;
}