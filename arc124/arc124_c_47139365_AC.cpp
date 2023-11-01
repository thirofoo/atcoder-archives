/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc124/submissions/47139365
 * Submitted at: 2023-11-01 22:37:41
 * Problem URL: https://atcoder.jp/contests/arc124/tasks/arc124_c
 * Result: AC
 * Execution Time: 48 ms
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

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 半分全列挙 ⇒ 約数全探索だとTL無理そう
    // 約数が最大公約数の候補 ⇒ 約数全列挙 ? (ここまで28分)
    ll n, cand; cin >> n;
    bool f = true;
    vector<ll> a(n), b(n), pf;
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = 1;
    rep(i,n) {
        pf = divisor(a[i]);
        for(auto ele:pf) {
            f = true; cand = b[i];
            rep(j,n) {
                if( i == j ) continue;
                if( a[j]%ele == 0 && b[j]%ele == 0 ) cand = gcd(cand, ( a[i] <= b[j] ? b[j] : a[j] )); 
                else if( a[j]%ele == 0 ) cand = gcd(cand, b[j]); 
                else if( b[j]%ele == 0 ) cand = gcd(cand, a[j]); 
                else {
                    f = false;
                    break;
                }
            }
            if( !f ) continue;
            ans = max(ans, ele*cand/gcd(ele,cand));
        }

        pf = divisor(b[i]);
        for(auto ele:pf) {
            f = true; cand = a[i];
            rep(j,n) {
                if( i == j ) continue;
                if( a[j]%ele == 0 && b[j]%ele == 0 ) cand = gcd(cand, ( a[i] <= b[j] ? b[j] : a[j] )); 
                else if( a[j]%ele == 0 ) cand = gcd(cand, b[j]); 
                else if( b[j]%ele == 0 ) cand = gcd(cand, a[j]); 
                else {
                    f = false;
                    break;
                }
            }
            if( !f ) continue;
            ans = max(ans, ele*cand/gcd(ele,cand));
        }
    }
    cout << ans << endl;
    
    return 0;
}