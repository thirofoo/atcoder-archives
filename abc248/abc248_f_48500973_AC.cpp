/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/48500973
 * Submitted at: 2023-12-15 11:14:57
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_f
 * Result: AC
 * Execution Time: 488 ms
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
    
    ll n, p; cin >> n >> p;
    vector dp(n,vector(n,vector<ll>(2,0)));
    // dp[i][j][k] : i列目まで見て辺をj本消し、2行が連結か否かがkの場合の数
    dp[0][1][0] = 1, dp[0][0][1] = 1;
    for(ll i=1; i<n; i++) {
        rep(j,n) {
            if( j-1 >= 0 ) dp[i][j][0] += dp[i-1][j-1][0];
            if( j-2 >= 0 ) dp[i][j][0] += dp[i-1][j-2][1]*2;
            dp[i][j][0] %= p;

            if( j-1 >= 0 ) dp[i][j][1] += dp[i-1][j-1][1]*3;
            dp[i][j][1] += dp[i-1][j][0];
            dp[i][j][1] += dp[i-1][j][1];
            dp[i][j][1] %= p;
        }
    }
    for(ll i=1; i<n; i++) cout << dp[n-1][i][1] << " ";
    cout << endl;
    
    return 0;
}