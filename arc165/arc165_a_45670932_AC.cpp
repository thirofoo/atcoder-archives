/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc165/submissions/45670932
 * Submitted at: 2023-09-17 21:07:00
 * Problem URL: https://atcoder.jp/contests/arc165/tasks/arc165_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<P> fact = factorize(n);
        if( fact.size() >= 2 ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}