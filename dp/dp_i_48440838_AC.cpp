/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/48440838
 * Submitted at: 2023-12-12 13:15:09
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_i
 * Result: AC
 * Execution Time: 115 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    // 小数第10位まで出力
    cout << setprecision(10) << fixed;
    ll n; cin >> n;
    vector<ld> p(n+1);
    for(ll i=1; i<=n; i++) cin >> p[i];
    // dp[i][j] : i番目のコインまで見て表がj枚出た時の確率
    vector dp(n+1,vector<ld>(n+1,0.0));
    dp[0][0] = 1.0; // 初期値設定
    for(ll i=1; i<=n; i++) {
        for(ll j=0; j<=n; j++) {
            if( j-1 >= 0 ) dp[i][j] += p[i]*dp[i-1][j-1];
            dp[i][j] += (1-p[i])*dp[i-1][j];
        }
    }
    ld ans = 0.0;
    for(ll i=n/2+1; i<=n; i++) ans += dp[n][i];
    cout << ans << endl;

    return 0;
}