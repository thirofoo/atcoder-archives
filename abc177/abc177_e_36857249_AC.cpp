/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/36857249
 * Submitted at: 2022-11-28 12:42:28
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_e
 * Result: AC
 * Execution Time: 100 ms
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

// d[i] : i以下の最小の素因数 (エラトステネスっぽく前計算)
vector<ll> d;

//素因数列挙ver (未圧縮)
set<ll> factorize(ll n){
    set<ll> pf;
    while(d[n] != -1){
        pf.insert(d[n]);
        n /= d[n];
    }
    return pf;
}

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    set<ll> st;
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    d.assign(1e6+5,-1);
    for(ll i=2;i<1e6+5;i++){
        if(d[i] != -1)continue;
        for(ll j=i;j<1e6+5;j+=i){
            if(d[j] == -1)d[j] = i;
        }
    }
    // set<ll> tmp = factorize(100);
    // for(auto ele:tmp)cout << ele << " ";
    // print();
    // return 0;

    ll e = a[0];
    rep(i,n)e = euclid(e,a[i]);
    if(e != 1)return print("not coprime"),0;

    rep(i,n){
        set<ll> tmp = factorize(a[i]);
        for(auto ele:tmp){
            if(st.count(ele))return print("setwise coprime"),0;
            st.insert(ele);
        }
    }
    print("pairwise coprime");
    
    return 0;
}