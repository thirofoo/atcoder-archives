/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc054/submissions/29039198
 * Submitted at: 2022-02-04 17:39:02
 * Problem URL: https://atcoder.jp/contests/abc054/tasks/abc054_d
 * Result: WA
 * Execution Time: 25 ms
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

vector<vector<P>> dp(405,vector<P>(405,P(-1,-1)));

int main() {
    int n,ma,mb; cin >> n >> ma >> mb;
    dp[0][0] = P(0,0);
    for(int k=1;k<=n;k++){
        int a,b,c; cin >> a >> b >> c;
        for(int i=1;i<=400;i++){
            for(int j=1;j<=400;j++){
                if(i >= a && j >= b && dp[i-a][j-b].second != -1 && dp[i-a][j-b].second != k){
                    if(dp[i][j].first == -1)dp[i][j] = P(dp[i-a][j-b].first+c,k);
                }
            }
        }
    }
    for(int i=1;i<=400;i++){
        if(i*ma > 400 || i*mb > 400)break;
        if(dp[ma*i][mb*i].first != -1){
            return cout << dp[ma*i][mb*i].first << endl,0;
        }
    }
    cout << -1 << endl;
    return 0;
}