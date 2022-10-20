/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/yahoo-procon2018-final-open/submissions/35807319
 * Submitted at: 2022-10-20 19:27:01
 * Problem URL: https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_a
 * Result: AC
 * Execution Time: 392 ms
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
vector<ll> factorize(ll n){
    vector<ll> pf;
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        pf.push_back(i);
    }
    if(a != 1)pf.push_back(a);
    return pf;
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
    vector<ll> cnt(200000),a(n);
    rep(i,n)input(a[i]);

    // 各a[i]がどの倍数かを求めておく
    rep(i,n){
        vector<ll> tmp = factorize(a[i]);
        ll size = tmp.size();
        for(ll j=1;j<(1LL << size);j++){
            ll now = 1;
            rep(k,size){
                if(j & (1LL << k))now *= tmp[k];
            }
            cnt[now]++;
        }
    }

    for(ll i=1;i<=m;i++){
        vector<ll> tmp = factorize(i);
        ll size = tmp.size(),ans = 0;
        for(ll j=1;j<(1LL << size);j++){
            ll now = 1,bit = 0;
            rep(k,size){
                if(j & (1LL << k)){
                    now *= tmp[k];
                    bit++;
                }
            }
            ans += cnt[now]*(bit%2 == 1 ? 1 : (-1));
        }
        print(n-ans);
    }
    
    return 0;
}