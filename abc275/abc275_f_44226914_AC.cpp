/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/44226914
 * Submitted at: 2023-08-04 16:45:09
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_f
 * Result: AC
 * Execution Time: 135 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<ll> a(n)   ;
    rep(i,n) cin >> a[i];
    // dp[i][j][k] : i文字目まで調べて、1個前をj(j == 1 で使った)して、総和kの時の操作回数最小
    vector dp(n+1,vector<vector<ll>>(2,vector<ll>(m+1,1e16)));
    dp[0][1][0] = 0;
    rep(i,n) {
        rep(j,m+1) {
            if( j+a[i] <= m ) dp[i+1][1][j+a[i]] = min( {dp[i+1][1][j+a[i]], dp[i][1][j], dp[i][0][j]} );
            dp[i+1][0][j] = min( {dp[i+1][0][j], dp[i][1][j]+1, dp[i][0][j]} );
        }
    }
    rep(i,m) {
        ll cand = min(dp[n][0][i+1], dp[n][1][i+1]);
        cout << (cand == 1e16 ? -1 : cand) << endl;
    }
    
    return 0;
}