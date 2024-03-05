/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc060/submissions/50919903
 * Submitted at: 2024-03-05 16:02:57
 * Problem URL: https://atcoder.jp/contests/abc060/tasks/arc073_b
 * Result: AC
 * Execution Time: 24 ms
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
    
    ll n, W; cin >> n >> W;
    vector<ll> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];
    ll w1 = w[0];
    rep(i,n) w[i] -= w1;
    vector dp(n+1,vector(n+1,vector<ll>(n*3+1,-1e16)));
    // dp[i][j][k] : i番目の品までみて、j個選んで、重さがkの時の価値の最大値
    dp[0][0][0] = 0;
    rep(i,n) rep(j,n) rep(k,n*3+1) {
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
        if( k+w[i] <= n*3 ) dp[i+1][j+1][k+w[i]] = max(dp[i+1][j+1][k+w[i]], dp[i][j][k]+v[i]);
    }
    ll ans = 0;
    rep(j,n+1) rep(k,n*3+1) if( w1*j+k <= W ) ans = max(ans, dp[n][j][k]);
    cout << ans << endl;
    
    return 0;
}