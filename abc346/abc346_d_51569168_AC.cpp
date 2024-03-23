/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc346/submissions/51569168
 * Submitted at: 2024-03-23 21:24:21
 * Problem URL: https://atcoder.jp/contests/abc346/tasks/abc346_d
 * Result: AC
 * Execution Time: 40 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    vector dp(n, vector(2,vector<ll>(3,1e16)));
    // dp[i][j][k] : i 文字目, 直前が j, 連続する箇所が k 個
    if( s[0] == '0' ) {
        dp[0][0][0] = 0;
        dp[0][1][0] = c[0];
    }
    else {
        dp[0][1][0] = 0;
        dp[0][0][0] = c[0];
    }
    rep(i,n-1) rep(j,2) rep(k,2) {
        if( s[i+1] == '0' ) {
            // flip する
            dp[i+1][1][k + (j == 1)] = min(dp[i+1][1][k + (j == 1)], dp[i][j][k] + c[i+1]);
            // flip しない
            dp[i+1][0][k + (j == 0)] = min(dp[i+1][0][k + (j == 0)], dp[i][j][k]);
        }
        else {
            // flip する
            dp[i+1][0][k + (j == 0)] = min(dp[i+1][0][k + (j == 0)], dp[i][j][k] + c[i+1]);
            // flip しない
            dp[i+1][1][k + (j == 1)] = min(dp[i+1][1][k + (j == 1)], dp[i][j][k]);
        }
    }
    ll ans = 1e16;
    rep(j,2) ans = min(ans, dp[n-1][j][1]);
    cout << ans << endl;
    
    return 0;
}