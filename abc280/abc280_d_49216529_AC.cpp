/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/49216529
 * Submitted at: 2024-01-11 19:21:00
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_d
 * Result: AC
 * Execution Time: 4 ms
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
    
    ll k; cin >> k;
    vector<P> pf = factorize(k);
    ll ans = 0;
    for(auto [p, cnt] : pf){
        ll left = 0, right = 1e16;
        while( right-left > 1 ) {
            ll mid = (left+right)/2, now = p, cand = 0;
            while( now <= mid ) {
                cand += mid/now;
                now *= p;
            }
            if( cand >= cnt ) right = mid;
            else left = mid;
        }
        ans = max(ans, right);
    }
    cout << ans << endl;
    
    return 0;
}