/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc090/submissions/29013439
 * Submitted at: 2022-02-03 00:56:18
 * Problem URL: https://atcoder.jp/contests/arc090/tasks/arc090_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<int>> dp(3,vector<int>(105,0));

int main() {
    int n; cin >> n;
    vector<vector<int>> candy(3,vector<int>(n+1));
    rep(i,2)rep(j,n)cin >> candy[i+1][j+1];
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            if(i == 1 && j == 1){dp[i][j] = candy[1][1]; continue;}
            dp[i][j] = max(dp[i-1][j]+candy[i][j],dp[i][j-1]+candy[i][j]);
        }
    }
    cout << dp[2][n] << endl;
    return 0;
}