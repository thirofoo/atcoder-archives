/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/46474415
 * Submitted at: 2023-10-12 19:23:38
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_e
 * Result: AC
 * Execution Time: 195 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll g = a[0];
    rep(i,n) g = gcd(g,a[i]);
    if( g != 1 ) return cout << "not coprime" << endl,0;
    
    // 素因数の個数は少ないはず？
    map<ll,ll> mp;
    rep(i,n) {
        vector<P> f = factorize(a[i]);
        for(auto [e,_]:f) {
            if( mp.count(e) ) return cout << "setwise coprime" << endl,0;
            mp[e]++;
        }
    }
    cout << "pairwise coprime" << endl;
    
    return 0;
}