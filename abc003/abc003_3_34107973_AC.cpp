/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc003/submissions/34107973
 * Submitted at: 2022-08-17 19:29:24
 * Problem URL: https://atcoder.jp/contests/abc003/tasks/abc003_3
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n,k; cin >> n >> k;
    vector<ll> m(n);
    rep(i,n)cin >> m[i];
    sort(m.begin(),m.end());
    vector<vector<ld>> dp(n+1,vector<ld>(k+5,-LLONG_MAX));
    dp[0][0] = 0;
    rep(i,n)rep(j,k){
        if(dp[i][j] == -LLONG_MAX)continue;
        dp[i+1][j+1] = max(dp[i+1][j+1],(dp[i][j]+m[i])/2);
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
    }

    ld ans = -LLONG_MAX;
    rep(i,k+1)ans = max(ans,dp[n][i]);
    cout << ans << endl;
    
    return 0;
}