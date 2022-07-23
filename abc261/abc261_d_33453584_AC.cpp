/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/33453584
 * Submitted at: 2022-07-23 21:27:04
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_d
 * Result: AC
 * Execution Time: 353 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m;cin >> n >> m;
    vector<ll> c(n+10,0),x(n);
    rep(i,n)cin >> x[i];
    rep(i,m){
        ll cost,y; cin >> cost >> y;
        c[cost] = y;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-LLONG_MAX));
    dp[0][0] = 0;
    rep(j,n){
        rep(i,n+1){
            if(dp[i][j] == -LLONG_MAX)continue;
            if(i != n)dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+x[j]+c[i+1]);
            dp[0][j+1] = max(dp[0][j+1],dp[i][j]);
        }
    }

    ll ans = -LLONG_MAX;
    rep(i,n+1)ans = max(ans,dp[i][n]);
    cout << ans << endl;
    
    return 0;
}