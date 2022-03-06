/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29924034
 * Submitted at: 2022-03-06 22:07:32
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_d
 * Result: AC
 * Execution Time: 78 ms
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
    vector<vector<ll>> dp(n+1,vector<ll>(w+5,-1));
    vector<ll> weight(n),value(n);
    rep(i,n)cin >> weight[i] >> value[i];
    dp[0][0] = 0;

    rep(i,n){
        rep(j,w+1){
            if(dp[i][j] == -1)continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j+weight[i] <= w){
                dp[i+1][j+weight[i]] = max(dp[i+1][j+weight[i]],dp[i][j]+value[i]);
            }
        }
    }

    ll ans = 0;
    rep(i,w+1)ans = max(ans,dp[n][i]);
    cout << ans << '\n';
    return 0;
}