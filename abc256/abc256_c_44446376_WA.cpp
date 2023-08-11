/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/44446376
 * Submitted at: 2023-08-11 09:46:34
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_c
 * Result: WA
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h1,h2,h3,w1,w2,w3; cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    ll ans = 0;
    for(ll i=1;i<h1;i++) {
        for(ll j=1;j<h1;j++) {
            if( i+j >= h1 ) continue;
            for(ll k=1;k<h2;k++) {
                for(ll l=1;l<h2;l++) {
                    if( k+l >= h2 ) continue;
                    ll m = h1 - (i+j);
                    ll n = h2 - (k+l);
                    ll low = (w1-(i+k)) + (w2-(j+l));
                    if( i+k < w1 && j+l < w2 && n+m < w3 && low < h3 ) ans++;
                }
            }       
        }
    }
    cout << ans << endl;
    
    return 0;
}