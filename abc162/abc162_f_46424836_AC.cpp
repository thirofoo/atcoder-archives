/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/46424836
 * Submitted at: 2023-10-10 14:26:50
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_f
 * Result: AC
 * Execution Time: 122 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector dp(n+1,vector(2,vector(4,vector<ll>(4,-1e16))));
    // dp[i][j][k][l] : i個目まで見て、直前がj(利用したか否か)、2連続未使用の回数k回、i==0 || i == n-1 を使った個数がl個の時の最大値
    dp[0][1][0][0] = 0;
    rep(i,n) {
        rep(j,2) {
            rep(k,3) {
                rep(l,3) {
                    // i個目未使用
                    dp[i+1][0][(!j?k+1:k)][l] = max({dp[i+1][0][(!j?k+1:k)][l],dp[i][j][k][l]});
                    // i個目使用
                    if( !j || i == 0 ) dp[i+1][1][k][l+(i==0||i==n-1)] = max({dp[i+1][1][k][l+(i==0||i==n-1)],dp[i][j][k][l]+a[i]});
                }
            }
        }
    }

    ll ans = -1e16;
    if( n%2 == 0 ) ans = max({ans,dp[n][0][0][1],dp[n][1][0][1],dp[n][1][1][2]});
    else ans = max({ans,dp[n][0][0][0],dp[n][0][1][1],dp[n][1][1][1],dp[n][0][2][2],dp[n][1][2][2]});
    cout << ans << endl;
    
    return 0;
}