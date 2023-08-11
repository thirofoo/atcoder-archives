/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/44446546
 * Submitted at: 2023-08-11 09:57:40
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_c
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h1,h2,h3,w1,w2,w3; cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    ll ans = 0;
    for(ll i=1;i<h1;i++) {
        for(ll j=1;j<h1;j++) {
            for(ll k=1;k<h2;k++) {
                for(ll l=1;l<h2;l++) {
                    ll m = h1 - (i+j);
                    ll n = h2 - (k+l);
                    ll o = w1 - (i+k);
                    ll p = w2 - (j+l);
                    if( m <= 0 || n <= 0 || o <= 0 || p <= 0 ) continue;
                    if( h3-(o+p) == w3-(n+m) && h3 != o+p && h3-(o+p) > 0 ) ans++;
                }
            }       
        }
    }
    cout << ans << endl;
    
    return 0;
}