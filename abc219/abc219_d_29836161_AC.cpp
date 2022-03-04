/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/29836161
 * Submitted at: 2022-03-04 13:06:16
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_d
 * Result: AC
 * Execution Time: 323 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,x,y; cin >> n >> x >> y;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(605,vector<int>(605,-1)));
    dp[0][0][0] = 0;
    vector<P> num;
    rep(i,n){
        int a,b; cin >> a >> b;
        num.push_back(P(a,b));
    }
    rep(i,n){
        auto [a,b] = num[i];
        for(int j=0;j<=300;j++){
            for(int k=0;k<=300;k++){
                if(dp[i][j][k] == -1)continue;
                
                if(dp[i+1][j][k] == -1)dp[i+1][j][k] = dp[i][j][k];
                else dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);

                if(dp[i+1][min(j+a,300)][min(k+b,300)] == -1)dp[i+1][min(j+a,300)][min(k+b,300)] = dp[i][j][k]+1;
                else dp[i+1][min(j+a,300)][min(k+b,300)] = min(dp[i+1][min(j+a,300)][min(k+b,300)],dp[i][j][k]+1);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=x;i<=300;i++){
        for(int j=y;j<=300;j++){
            if(dp[n][i][j] == -1)continue;
            ans = min(ans,dp[n][i][j]);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return 0;
}