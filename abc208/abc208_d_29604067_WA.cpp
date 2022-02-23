/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29604067
 * Submitted at: 2022-02-23 18:20:27
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_d
 * Result: WA
 * Execution Time: 138 ms
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
    int n,m; cin >> n >> m;
    vector<vector<P>> Graph(n);
    vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        Graph[a-1].push_back(P(b-1,c));
        dp[a-1][b-1] = c;
    }
    rep(i,n)dp[i][i] = 0;
    //ワーシャルフロイド
    rep(k,n)rep(i,n)rep(j,n){
        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    int ans = 0;
    rep(i,n)rep(j,n){
        if(dp[i][j] != INT_MAX)ans += dp[i][j];
    }
    cout << ans << endl;
    return 0;
}