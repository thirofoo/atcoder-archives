/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46331718
 * Submitted at: 2023-10-07 21:53:13
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_e
 * Result: TLE
 * Execution Time: 2048 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x; cin >> n >> x;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    vector dp(x+2,vector<mint>(2,0));
    vector f(x+2,vector<bool>(2,false));
    f[0][0] = true;
    dp[0][0] = 1;
    rep(i,x+1) {
        rep(j,n) {
            if( j == 0 ) {
                if( f[i][0] ) {
                    dp[min(i+t[j],x+1)][1] += dp[i][0] / n;
                    f[min(i+t[j],x+1)][1] = true;
                }
                if( f[i][1] ) {
                    dp[min(i+t[j],x+1)][1] += dp[i][1] / n;
                    f[min(i+t[j],x+1)][1] = true;
                }
            }
            else {
                if( f[i][0] ) {
                    dp[min(i+t[j],x+1)][0] += dp[i][0] / n;
                    f[min(i+t[j],x+1)][0] = true;
                }
                if( f[i][1] ) {
                    dp[min(i+t[j],x+1)][0] += dp[i][1] / n;
                    f[min(i+t[j],x+1)][0] = true;
                }
            }
        }
    }
    // rep(i,x+2) cout << dp[i][0].val() << " " << dp[i][1].val() << endl;
    cout << dp[x+1][1].val() << endl;
    
    return 0;
}