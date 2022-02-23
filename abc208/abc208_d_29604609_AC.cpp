/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29604609
 * Submitted at: 2022-02-23 18:49:15
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_d
 * Result: AC
 * Execution Time: 160 ms
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
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e12));
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        dp[a-1][b-1] = c;
    }
    rep(i,n)dp[i][i] = 0;
    //ワーシャルフロイド
    ll ans = 0;
    rep(k,n){
        rep(i,n)rep(j,n){
            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            if(dp[i][j] != 1e12)ans += dp[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}