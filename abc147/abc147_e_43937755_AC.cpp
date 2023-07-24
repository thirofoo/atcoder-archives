/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc147/submissions/43937755
 * Submitted at: 2023-07-25 01:54:41
 * Problem URL: https://atcoder.jp/contests/abc147/tasks/abc147_e
 * Result: AC
 * Execution Time: 41 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<vector<ll>> a(h,vector<ll>(w)), b(h,vector<ll>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    rep(i,h)rep(j,w) cin >> b[i][j];
    // 折り返しを考慮すべく 10000を起点にして行うことで bitset 高速化可能！
    ll base = 10000;
    vector dp(h,vector<bitset<20000>>(w,0));
    dp[0][0].set( base + (a[0][0] - b[0][0]) );
    dp[0][0].set( base - (a[0][0] - b[0][0]) );
    rep(i,h) {
        rep(j,w) {
            ll diff = abs(a[i][j]-b[i][j]);
            if( !outField(i-1,j,h,w) ) {
                dp[i][j] |= (dp[i-1][j] << diff);
                dp[i][j] |= (dp[i-1][j] >> diff);
            }
            if( !outField(i,j-1,h,w) ) {
                dp[i][j] |= (dp[i][j-1] << diff);
                dp[i][j] |= (dp[i][j-1] >> diff);
            }
        }
    }
    rep(i,10000){
        if( dp[h-1][w-1][ base+i ] ) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}