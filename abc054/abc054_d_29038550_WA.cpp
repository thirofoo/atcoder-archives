/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/29038550
 * Submitted at: 2022-02-04 17:05:24
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_d
 * Result: WA
 * Execution Time: 838 ms
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

vector<vector<int>> dp(4005,vector<int>(4005,-1));

int main() {
    int n,ma,mb; cin >> n >> ma >> mb;
    dp[0][0] = 0;
    for(int k=1;k<=n;k++){
        int a,b,c; cin >> a >> b >> c;
        for(int i=1;i<=4000;i++){
            for(int j=1;j<=4000;j++){
                if(i >= a && j >= b && dp[i-a][j-b] != -1 && dp[i-a][j-b] != k){
                    if(dp[i][j] == -1)dp[i][j] = k;
                    else dp[i][j] = min(k,dp[i][j]);
                }
            }
        }
    }
    for(int i=1;i<=4000;i++){
        if(i*ma > 4000 || i*mb > 4000)break;
        if(dp[i*ma][i*mb] != -1)return cout << i << endl,0;
    }
    cout << -1 << endl;
    return 0;
}