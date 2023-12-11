/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/48434017
 * Submitted at: 2023-12-12 00:36:53
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_a
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    vector<ll> h(n), dp(n,1e14);
    for(ll i=0; i<n; i++) cin >> h[i];
    dp[0] = 0, dp[1] = abs(h[0]-h[1]); // 初期値設定
    for(ll i=2; i<n; i++) {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i]);
        dp[i] = min(dp[i-2]+abs(h[i]-h[i-2]), dp[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}