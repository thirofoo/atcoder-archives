/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/50889998
 * Submitted at: 2024-03-04 08:55:43
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_e
 * Result: AC
 * Execution Time: 133 ms
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
    vector<ll> a(n+1,0);
    rep(i, n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(n+1,-1e16));
    // dp[i][j] : i日目まで見て、直前の休日が j 日前のときの最大値
    dp[0][0] = 0;
    rep(i,n-1) rep(j,n+1) {
        // 平日の場合
        if( j != n ) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        // 休日の場合
        dp[i+1][0] = max(dp[i+1][0], dp[i][j] + a[j/2]*2 + (j%2 == 1 ? a[j/2+1]-a[j/2] : 0));
    }
    ll ans = -1e16;
    rep(i,n+1) ans = max(ans, dp[n-1][i] + a[i/2]*2 + (i%2 == 1 ? a[i/2+1]-a[i/2] : 0));
    cout << ans << endl;
    
    return 0;
}