/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/46468469
 * Submitted at: 2023-10-12 14:31:36
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_f
 * Result: WA
 * Execution Time: 146 ms
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
    
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector dp(n+1,vector(n+1,vector<ll>(n,-1)));
    // dp[i][j][k][l] : i個目まで見て, 個数j, 総和 mod kでの総和最大値
    dp[0][0][0] = 0;
    rep(i,n) {
        rep(j,n) {
            rep(k,n) {
                if( dp[i][j][k] == -1 ) continue;
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                rep(l,n) {
                    if( dp[i][j][k]+a[i] <= x ) {
                        dp[i+1][j+1][(dp[i][j][k]+a[i])%(l+1)] = max(dp[i+1][j+1][(dp[i][j][k]+a[i])%(l+1)], dp[i][j][k]+a[i]);
                    }
                }
            }
        }
    }
    // rep(k,n+1) {
    //     rep(i,n+1) {
    //         rep(j,n) cerr << dp[k][i][j] << " ";
    //         cerr << endl;
    //     }
    //     cerr << endl;
    // }
    ll ans = 1e18 + 5;
    rep(i,n) {
        if( (x-dp[n][i+1][i])%(i+1) != 0 ) continue;
        ans = min(ans,(x-dp[n][i+1][i])/(i+1));
    }
    cout << ans << endl;
    
    return 0;
}