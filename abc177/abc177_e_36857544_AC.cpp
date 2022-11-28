/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/36857544
 * Submitted at: 2022-11-28 13:10:46
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_e
 * Result: AC
 * Execution Time: 103 ms
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

// d[i] : i以下の最小の素因数 (エラトステネス風に前計算)
vector<ll> d;
void fact_prepare(ll n){
    // n以下の高速化前計算
    n++;
    d.assign(n,0);
    for(ll i=2;i<n;i++){
        if(d[i])continue;
        for(ll j=i;j<n;j+=i){
            if(!d[j])d[j] = i;
        }
    }
}

//素因数列挙ver (圧縮)
vector<P> factorize(ll n){
    vector<P> pf;
    if(n == 1)return pf;
    ll num = d[n],cnt = 0;
    while(n != 1){
        if(num == d[n])cnt++;
        else{
            pf.push_back(P(num,cnt));
            num = d[n];
            cnt = 1;
        }
        n /= d[n];
    }
    if(num)pf.push_back(P(num,cnt));
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
    vector<bool> cnt(1e6+5,false);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    fact_prepare(1e6+5);

    ll e = a[0];
    rep(i,n)e = euclid(e,a[i]);
    if(e != 1)return print("not coprime"),0;

    rep(i,n){
        vector<P> tmp = factorize(a[i]);
        for(auto ele:tmp){
            if(cnt[ele.first])return print("setwise coprime"),0;
            cnt[ele.first] = true;
        }
    }
    print("pairwise coprime");
    
    return 0;
}