/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc147/submissions/50890104
 * Submitted at: 2024-03-04 09:07:30
 * Problem URL: https://atcoder.jp/contests/abc147/tasks/abc147_e
 * Result: WA
 * Execution Time: 182 ms
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
    
    ll h, w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w)), b(h,vector<ll>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    const ll mid = 4000;
    vector dp(h,vector(w,vector<bool>(mid*2+5,false)));
    // dp[i][j][k] : (i,j) までのマスを見て偏りが k のケースが存在するか
    dp[0][0][a[0][0]-b[0][0]+mid] = true;
    dp[0][0][b[0][0]-a[0][0]+mid] = true;
    rep(i,h) rep(j,w) rep(k,mid*2+5) {
        if( !dp[i][j][k] ) continue;

        // 縦移動
        if( i != h-1 ) {
            ll diff = k+(a[i+1][j]-b[i+1][j]);
            if( 0 <= diff && diff < mid*2+5 ) dp[i+1][j][diff] = true;
            diff = k+(b[i+1][j]-a[i+1][j]);
            if( 0 <= diff && diff < mid*2+5 ) dp[i+1][j][diff] = true;
        }
        // 横移動
        if( j != w-1 ) {
            ll diff = k+(a[i][j+1]-b[i][j+1]);
            if( 0 <= diff && diff < mid*2+5 ) dp[i][j+1][diff] = true;
            diff = k+(b[i][j+1]-a[i][j+1]);
            if( 0 <= diff && diff < mid*2+5 ) dp[i][j+1][diff] = true;
        }
    }
    ll ans = 1e16;
    rep(i,mid*2+5) if( dp[h-1][w-1][i] ) ans = min(ans,abs(i-mid));
    cout << ans << endl;
    
    return 0;
}