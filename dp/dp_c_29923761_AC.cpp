/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29923761
 * Submitted at: 2022-03-06 21:57:46
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_c
 * Result: AC
 * Execution Time: 73 ms
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
    int n; cin >> n;
    vector<vector<int>> dp(n+5,vector<int>(3,0));
    vector<int> a(n),b(n),c(n);
    rep(i,n)cin >> a[i] >> b[i] >> c[i];
    dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0];
    rep(i,n-1){
        rep(j,3){
            if(j != 0)dp[i+1][0] = max(dp[i+1][0],dp[i][j]+a[i+1]);
            if(j != 1)dp[i+1][1] = max(dp[i+1][1],dp[i][j]+b[i+1]);
            if(j != 2)dp[i+1][2] = max(dp[i+1][2],dp[i][j]+c[i+1]);
        }
    }

    int ans = 0;
    rep(i,3)ans = max(ans,dp[n-1][i]);
    cout << ans << '\n';
    return 0;
}