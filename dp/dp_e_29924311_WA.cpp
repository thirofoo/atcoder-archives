/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29924311
 * Submitted at: 2022-03-06 22:19:03
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_e
 * Result: WA
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,w; cin >> n >> w;
    vector<vector<ll>> dp(n+1,vector<ll>(10005,-1));
    vector<ll> weight(n),value(n);
    rep(i,n)cin >> weight[i] >> value[i];
    dp[0][0] = 0;

    rep(i,n){
        rep(j,10001){
            if(dp[i][j] == -1)continue;
            
            if(dp[i+1][j] != -1)dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            else dp[i+1][j] = dp[i][j];

            if(j+value[i] <= 10000){
                dp[i+1][j+value[i]] = max(dp[i+1][j+value[i]],dp[i][j]+weight[i]);
            }
        }
    }

    ll ans = 0;
    rep(i,10001){
        if(0 <= dp[n][i] && dp[n][i] <= w)ans = max(ans,i);
    }
    cout << ans << '\n';
    return 0;
}