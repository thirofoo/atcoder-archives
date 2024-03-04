/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc147/submissions/50890350
 * Submitted at: 2024-03-04 09:29:55
 * Problem URL: https://atcoder.jp/contests/abc147/tasks/abc147_e
 * Result: AC
 * Execution Time: 17 ms
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
    const ll mid = 11000;
    vector dp(h,vector(w,bitset<mid*2+5>(0)));
    // dp[i][j][k] : (i,j) までのマスを見て偏りが k のケースが存在するか
    // ※ bitset で高速化 ver
    dp[0][0].set(a[0][0]-b[0][0]+mid);
    dp[0][0].set(b[0][0]-a[0][0]+mid);
    ll diff;

    rep(i,h) rep(j,w) {
        // 縦移動
        if( i != h-1 ) {
            diff = abs(a[i+1][j]-b[i+1][j]);
            dp[i+1][j] |= (dp[i][j] << diff);
            dp[i+1][j] |= (dp[i][j] >> diff);
        }

        // 横移動
        if( j != w-1 ) {
            diff = abs(a[i][j+1]-b[i][j+1]);
            dp[i][j+1] |= (dp[i][j] << diff);
            dp[i][j+1] |= (dp[i][j] >> diff);
        }
    }
    ll ans = 1e16;
    rep(i,mid*2+5) if( dp[h-1][w-1].test(i) ) ans = min(ans,abs(i-mid));
    cout << ans << endl;
    
    return 0;
}