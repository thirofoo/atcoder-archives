/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43903249
 * Submitted at: 2023-07-23 17:37:46
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_f
 * Result: AC
 * Execution Time: 79 ms
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
    
    // 解説AC
    // 発想が凄い。右端から前の列を状態として持って遷移。

    ll n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,m){
            if( s[i][j] == '.' ) continue;
            if( i != n-1 ) s[i+1][j] = '#';
            if( i != n-1 && j != m-1 ) s[i+1][j+1] = '#';
        }
    }
    vector<vector<mint>> dp(n+3,vector<mint>(m+1,0));
    dp[0][m]++;

    for(ll j=m-1;j>=0;j--){
        rep(i,n+1){
            dp[i][j] = dp[0][j+1] - dp[i+2][j+1];
            if( i == n || s[i][j] == '#' ) break;
        }
        for(ll i=n+1;i>0;i--) dp[i-1][j] += dp[i][j];
    }
    cout << dp[0][0].val() << endl;
    
    return 0;
}