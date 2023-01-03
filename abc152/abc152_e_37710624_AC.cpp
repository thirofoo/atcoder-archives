/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc152/submissions/37710624
 * Submitted at: 2023-01-03 16:56:27
 * Problem URL: https://atcoder.jp/contests/abc152/tasks/abc152_e
 * Result: AC
 * Execution Time: 60 ms
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
typedef modint1000000007 mint;
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
    if(n <= 1)return pf;
    ll num = d[n],cnt = 0;
    while(d[n]){
        if(d[n] == num)cnt++;
        else {
            pf.push_back(P(num,cnt));
            num = d[n];
            cnt = 1;
        }
        n /= d[n];
    }
    pf.push_back(P(num,cnt));
    return pf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> p(n);
    rep(i,n)input(p[i]);
    fact_prepare(2e6);

    vector<vector<P>> pf;
    vector<ll> cnt(2e6,0);
    mint ans = 0;
    rep(i,n){
        pf.push_back(factorize(p[i]));
        for(auto [num,c]:pf[i])cnt[num] = max(c,cnt[num]);
    }
    mint tmp = 1;
    rep(i,2e6){
        if(!cnt[i])continue;
        rep(j,cnt[i])tmp *= i;
    }
    rep(i,n){
        mint t = tmp;
        for(auto [num,c]:pf[i]){
            rep(j,c)t /= num;
        }
        ans += t;
    }
    print(ans.val());
    
    return 0;
}