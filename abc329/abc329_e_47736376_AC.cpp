/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47736376
 * Submitted at: 2023-11-19 00:21:30
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_e
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; string s, t; cin >> n >> m >> s >> t;
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0] = true;
    // dp[i][j] : Sのi文字目まで見て、Tのj文字目が入るケースが存在するか否か
    rep(i,n) {
        rep(j,m) {
            if( !dp[i][j] ) continue;
            dp[i+1][j+1] = dp[i+1][j+1] || (s[i] == t[j]);
            if( s[i] == t[0] ) dp[i+1][1] = true;
        }
        // 最後まで T を用いた時は下にめり込ませられる
        if( dp[i][m] ) rep(j,m) dp[i+1][j+1] = dp[i+1][j+1] || (s[i] == t[j]);
    }
    cout << ( dp[n][m] ? "Yes" : "No" ) << endl;
    
    return 0;
}