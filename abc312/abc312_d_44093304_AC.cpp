/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44093304
 * Submitted at: 2023-07-30 09:21:05
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_d
 * Result: AC
 * Execution Time: 59 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 深さを利用したdp ver
    string s; cin >> s;
    ll n = s.size();
    vector<vector<mint>> dp(n+1,vector<mint>(n+1,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,n){
            if( s[i] == '(' ) dp[i+1][j+1] += dp[i][j];
            else if( s[i] == ')' ) {
                if( j != 0 ) dp[i+1][j-1] += dp[i][j];
            }
            else {
                dp[i+1][j+1] += dp[i][j];
                if( j != 0 ) dp[i+1][j-1] += dp[i][j];
            }
        }
    }
    cout << dp[n][0].val() << endl;
    
    return 0;
}