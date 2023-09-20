/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/45740852
 * Submitted at: 2023-09-20 10:24:43
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_d
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
    ll ans = 0;
    for(ll i=1;i<=n;i++) {
        vector pf = factorize(i);
        ll tmp = 1;
        for(auto &&[p,num]:pf) {
            if( num%2 == 0 ) continue;
            tmp *= p;
        }
        ll left = 1, right = n+1;
        while( right-left > 1 ) {
            ll mid = (right+left)/2;
            if( tmp*mid*mid <= n ) left = mid;
            else right = mid;
        }
        ans += left;
    }
    cout << ans << endl;
    
    return 0;
}