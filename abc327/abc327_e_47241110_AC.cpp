/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47241110
 * Submitted at: 2023-11-04 21:29:28
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_e
 * Result: AC
 * Execution Time: 296 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    vector<ld> p(n);
    rep(i,n) cin >> p[i];
    reverse(p.begin(), p.end());
    vector<vector<ld>> dp(n+1,vector<ld>(n+1,-1e9));
    vector<ld> r(n+1,1.0), r2(n+1,1.0);
    rep(i,n) {
        r[i+1] = r[i]*(ld)0.9;
        r2[i+1] = r2[i] + r[i+1];
    }
    dp[0][0] = 0.0;
    rep(i,n) {
        rep(j,n) {
            if( dp[i][j] == -1e9 ) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+p[i]*r[j]);
        }
    }
    ld ans = -1e9;
    for(int i=1; i<=n; i++) {
        if( dp[n][i] == -1e9 ) continue;
        cerr << dp[n][i]/r2[i-1] - (ld)1200/sqrt(i) << endl;
        ans = max(ans, dp[n][i]/r2[i-1] - (ld)1200/sqrt(i));
    }
    cout << ans << endl;
    
    return 0;
}