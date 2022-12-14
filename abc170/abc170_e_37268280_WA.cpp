/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/37268280
 * Submitted at: 2022-12-14 19:32:54
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_e
 * Result: WA
 * Execution Time: 428 ms
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

S op(S a,S b){return min(a,b);} // operator(作用素)
S e(){return LLONG_MAX;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; input(n,q);
    vector<ll> school(n),rate(n);
    vector<multiset<ll>> info(200005);
    rep(i,n){
        ll a,b; input(a,b);
        rate[i] = a;
        school[i] = b;
        info[b].insert(a);
    }

    segtree<S,op,e> sg(200005);
    rep(i,200005){
        if(info[i].empty())sg.set(i,LLONG_MAX);
        else sg.set(i,*info[i].rend());
    }

    while(q--){
        ll c,d; input(c,d); c--;
        info[school[c]].erase(info[school[c]].find(rate[c]));
        info[d].insert(rate[c]);

        // segtree更新
        if(info[school[c]].empty())sg.set(school[c],LLONG_MAX);
        else sg.set(school[c],*info[school[c]].rend());
        sg.set(d,*info[d].rend());

        school[c] = d;
        print(sg.all_prod());
    }
    
    return 0;
}