/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34390485
 * Submitted at: 2022-08-27 21:43:43
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_d
 * Result: AC
 * Execution Time: 45 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> bird(1e5+6,vector<ll>(5,0));
    rep(i,n){
        ll t,x,a; cin >> t >> x >> a;
        bird[t][x] = a;
    }
    vector<vector<ll>> dp(1e5+6,vector<ll>(5,-LLONG_MAX));
    dp[0][0] = 0;
    rep(i,1e5+5){
        rep(j,5){
            if(dp[i][j] == -LLONG_MAX)continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]+bird[i+1][j]);
            if(j != 0)dp[i+1][j-1] = max(dp[i+1][j-1],dp[i][j]+bird[i+1][j-1]);
            if(j != 4)dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+bird[i+1][j+1]);
        }
    }

    ll ans = -LLONG_MAX;
    rep(i,5)ans = max(ans,dp[1e5][i]);
    cout << ans << endl;
    
    return 0;
}