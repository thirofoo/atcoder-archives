/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/48440146
 * Submitted at: 2023-12-12 12:20:02
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_d
 * Result: AC
 * Execution Time: 45 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, W; cin >> n >> W;
    vector<ll> w(n+1), v(n+1);
    for(ll i=1; i<=n; i++) cin >> w[i] >> v[i];
    // dp[i][j] : i番目の品物まで見て重さの総和がjの時の最大価値
    vector dp(n+1,vector<ll>(W+1,-1e16));
    dp[0][0] = 0; // 初期値は (0,0) だけ 0 , 他は小さい値
    for(ll i=1; i<=n; i++) {
        for(ll j=0; j<=W; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if( j-w[i] >= 0 ) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
        }
    }
    ll ans = 0;
    for(ll i=0; i<=W; i++) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}