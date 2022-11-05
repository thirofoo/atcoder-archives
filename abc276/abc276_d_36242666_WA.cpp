/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36242666
 * Submitted at: 2022-11-05 21:35:48
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_d
 * Result: WA
 * Execution Time: 225 ms
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

//素因数列挙ver(圧縮ver)
vector<P> factorize(ll n){
    vector<P> pf;
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        pf.push_back(P(i,cnt));
    }
    if(a != 1)pf.push_back(P(a,1));
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    ll e = a[0];
    rep(i,n)e = euclid(e,a[i]);
    rep(i,n){
        a[i] /= e;
        if(a[i]%2 && a[i]%3 && a[i] != 1)return print(-1),0;
    }

    ll ans = 0;
    rep(i,n){
        vector<P> f = factorize(a[i]);
        for(auto [num,c]:f){
            if(num == 2)ans += c;
            else if(num == 3)ans += c;
            else break;
        }
    }
    print(ans);
    
    return 0;
}