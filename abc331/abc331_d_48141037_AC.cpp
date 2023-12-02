/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48141037
 * Submitted at: 2023-12-02 22:27:38
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_d
 * Result: AC
 * Execution Time: 289 ms
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
    
    ll n, q; cin >> n >> q;
    vector<string> p(n);
    rep(i,n) cin >> p[i];

    vector<vector<vector<ll>>> dps;
    vector<vector<ll>> dp;
    dp.assign(n+2,vector<ll>(n+2,0));
    for(ll i=1; i<=n; i++)for(ll j=1; j<=n; j++) {
        dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1] + (p[i-1][j-1] == 'B');
    }
    dps.emplace_back(dp);
    dp.assign(n+2,vector<ll>(n+2,0));
    for(ll i=1; i<=n; i++)for(ll j=n; j>=1; j--) {
        dp[i][j] = dp[i-1][j]+dp[i][j+1]-dp[i-1][j+1] + (p[i-1][j-1] == 'B');
    }
    dps.emplace_back(dp);
    dp.assign(n+2,vector<ll>(n+2,0));
    for(ll i=n; i>=1; i--)for(ll j=1; j<=n; j++) {
        dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1] + (p[i-1][j-1] == 'B');
    }
    dps.emplace_back(dp);
    dp.assign(n+2,vector<ll>(n+2,0));
    for(ll i=n; i>=1; i--)for(ll j=n; j>=1; j--) {
        dp[i][j] = dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1] + (p[i-1][j-1] == 'B');
    }
    dps.emplace_back(dp);
    while( q-- ) {
        ll x1, y1, x3, y3; cin >> x1 >> y1 >> x3 >> y3;
        ll x2 = x1, y2 = y3, x4 = x3, y4 = y1;

        ll ans = dps[3][x1%n+1][y1%n+1] + dps[2][x2%n+1][y2%n+1] + dps[0][x3%n+1][y3%n+1] + dps[1][x4%n+1][y4%n+1];
        // cerr << dps[3][x1%n+1][y1%n+1] << " " << dps[2][x2%n+1][y2%n+1] << " " << dps[0][x3%n+1][y3%n+1] << " " << dps[1][x4%n+1][y4%n+1] << endl;
        // cerr << ans << " ";
        ans += dps[1][n][y1%n+1]*(abs(x3/n-x1/n)-1); // 左
        // cerr << ans << " ";
        ans += dps[0][n][y3%n+1]*(abs(x3/n-x1/n)-1); // 右
        // cerr << ans << " ";
        ans += dps[2][x1%n+1][n]*(abs(y3/n-y1/n)-1); // 上
        // cerr << ans << " ";
        ans += dps[0][x3%n+1][n]*(abs(y3/n-y1/n)-1); // 下
        // cerr << ans << endl;
        ans += dps[0][n][n]*(abs(x3/n-x1/n)-1)*(abs(y3/n-y1/n)-1);
        cout << ans << endl;
    }
    
    return 0;
}