/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49280113
 * Submitted at: 2024-01-14 21:02:09
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_b
 * Result: AC
 * Execution Time: 2 ms
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
    vector<P> pf = factorize(n);
    ll ans = 0;
    for(auto [p, cnt] : pf) {
        if( p == 2 ) ans = cnt;
    }
    cout << ans << endl;
    
    return 0;
}