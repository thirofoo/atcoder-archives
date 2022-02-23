/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29604260
 * Submitted at: 2022-02-23 18:30:58
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_d
 * Result: WA
 * Execution Time: 529 ms
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
    ll n,m; cin >> n >> m;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(n+1,vector<ll>(n,INT_MAX)));
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        dp[0][a-1][b-1] = c;
    }
    rep(i,n)dp[0][i][i] = 0;
    //ワーシャルフロイド
    rep(k,n)rep(i,n)rep(j,n){
        dp[k+1][i][j] = min(dp[k][i][j],dp[k][i][k]+dp[k][k][j]);
    }
    int ans = 0;
    for(int k=1;k<=n;k++)rep(i,n)rep(j,n){
        if(dp[k][i][j] != INT_MAX)ans += dp[k][i][j];
    }
    cout << ans << endl;
    return 0;
}