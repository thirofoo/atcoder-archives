/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44062430
 * Submitted at: 2023-07-29 21:54:28
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_d
 * Result: AC
 * Execution Time: 67 ms
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
    
    string s; cin >> s;
    ll n = s.size();
    if( s.size()%2 == 1 ) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<mint>> dp(n+2,vector<mint>(n+2,0));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,i+1){
            if( s[i] == '(' ) {
                dp[j+1][i-j] += dp[j][i-j];
            }
            else if( s[i] == ')' ) {
                if( j != i-j ) dp[j][i-j+1] += dp[j][i-j];
            }
            else {
                dp[j+1][i-j] += dp[j][i-j];
                if( j != i-j ) dp[j][i-j+1] += dp[j][i-j];
            }
        }
    }
    cout << dp[n/2][n/2].val() << endl;
    
    return 0;
}