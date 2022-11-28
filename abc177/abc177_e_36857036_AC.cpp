/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/36857036
 * Submitted at: 2022-11-28 12:24:27
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_e
 * Result: AC
 * Execution Time: 457 ms
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

//素因数列挙ver(圧縮してないver)
vector<ll> factorize(ll n){
    vector<ll> pf;
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        if(a%i)continue;
        pf.push_back(i);
        while(a%i == 0)a /= i;
    }
    if(a != 1)pf.push_back(a);
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
    ll e = a[0];
    rep(i,n)e = euclid(e,a[i]);
    if(e != 1)return print("not coprime"),0;

    rep(i,n){
        vector<ll> tmp = factorize(a[i]);
        for(auto ele:tmp){
            if(st.count(ele))return print("setwise coprime"),0;
            st.insert(ele);
        }
    }
    print("pairwise coprime");
    
    return 0;
}