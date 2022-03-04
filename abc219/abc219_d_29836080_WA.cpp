/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/29836080
 * Submitted at: 2022-03-04 12:58:49
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_d
 * Result: WA
 * Execution Time: 421 ms
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
        rep(j,601){
            rep(k,601){
                if(dp[i][j][k] == -1)continue;
                
                if(dp[i+1][j][k] == -1)dp[i+1][j][k] = dp[i][j][k];
                else dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]);
                
                if(j+a > 600 || k+b > 600)continue;

                if(dp[i+1][j+a][k+b] == -1)dp[i+1][j+a][k+b] = dp[i][j][k]+1;
                else dp[i+1][j+a][k+b] = min(dp[i+1][j+a][k+b],dp[i][j][k]+1);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=x;i<600;i++){
        for(int j=y;j<600;j++){
            if(dp[n][i][j] == -1)continue;
            ans = min(ans,dp[n][i][j]);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return 0;
}