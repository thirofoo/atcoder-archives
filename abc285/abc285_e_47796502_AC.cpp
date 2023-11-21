/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/47796502
 * Submitted at: 2023-11-21 13:57:47
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_e
 * Result: AC
 * Execution Time: 143 ms
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
    // 初日を休日に固定
    // dp[i][j] : i日目まで考えてj連続平日の時の生産性最大値
    vector dp(n,vector<ll>(n+1,-1e16));
    vector<ll> r(n+1,0);
    rep(i,n) r[i+1] = r[i]+a[i/2];
    dp[0][0] = 0;
    for(ll i=0; i<n-1; i++) {
        rep(j,n) {
            dp[i+1][0] = max(dp[i+1][0], dp[i][j]+r[j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
        }
    }
    ll ans = 0;
    rep(i,n+1) ans = max(ans, dp[n-1][i]+r[i]);
    cout << ans << endl;
    
    return 0;
}