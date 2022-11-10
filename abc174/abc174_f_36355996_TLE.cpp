/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/36355996
 * Submitted at: 2022-11-10 13:06:49
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_f
 * Result: TLE
 * Execution Time: 2209 ms
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
struct node{
    int num = 0;
    vector<int> v;
};
using S = node;

// operator(作用素)
S op(S a,S b){{
    auto [n1,v1] = b;
    auto [n2,v2] = a;
    vector<int> next;
    set<int> st;
    int idx = 0,nnum = n1+n2,size = v2.size();
    for(auto node1:v1){
        while(idx != size && node1 >= v2[idx]){
            next.push_back(v2[idx]);
            if(node1 == v2[idx])st.insert(node1);
            idx++;
        }
        next.push_back(node1);
    }
    while(idx != size){
        next.push_back(v2[idx]);
        idx++;
    }
    return {nnum-st.size(),next};
}}
// 単位元 (op(e,a) = a)
S e(){return {0,{}};}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // merge sortっぽく区間が管理出来ればNlogNで行けそう(?)
    ll n,q; input(n,q);
    vector<S> c;
    rep(i,n){
        int tmp; input(tmp);
        c.push_back({1,{tmp}});
    }
    segtree<S,op,e> sg(c);

    while(q--){
        ll l,r; input(l,r); l--;
        print(sg.prod(l,r).num);
    }
    
    return 0;
}