/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43870441
 * Submitted at: 2023-07-22 22:13:33
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_e
 * Result: AC
 * Execution Time: 110 ms
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
    
    ll h,w,n; cin >> h >> w >> n;
    vector<vector<ll>> dp(h+1,vector<ll>(w+1,1e16));
    vector<P> p;
    rep(i,n){
        ll a,b; cin >> a >> b;
        a--; b--;
        p.push_back( P(a,b) );
        dp[a][b] = 0;
    }
    rep(i,h) dp[i][w] = 0;
    rep(i,w) dp[h][i] = 0;
    for(ll i=h-1;i>=0;i--){
        for(ll j=w-1;j>=0;j--){
            dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
            dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
            dp[i][j] = min(dp[i][j], dp[i+1][j+1]+1);
        }
    }

    // 左上全探索 → 右下は単調性あり
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if( dp[i][j] == 1e16 ) ans += max(h-i, w-j);
            else ans += dp[i][j];
        }
    }
    cout << ans << endl;
    
    
    return 0;
}