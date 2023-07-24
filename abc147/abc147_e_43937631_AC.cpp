/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc147/submissions/43937631
 * Submitted at: 2023-07-25 01:40:57
 * Problem URL: https://atcoder.jp/contests/abc147/tasks/abc147_e
 * Result: AC
 * Execution Time: 745 ms
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
    // 各マスにおいて差がどれだけ付くかを状態に持つdpが出来そう
    vector dp(h,vector<vector<bool>>(w,vector<bool>(10000,false)));

    dp[0][0][abs(a[0][0]-b[0][0])] = true;

    rep(i,h) {
        rep(j,w) {
            rep(k,10000){
                ll next_diff1 = abs(k-abs(a[i][j]-b[i][j]));
                ll next_diff2 = k+abs(a[i][j]-b[i][j]);
                if( !outField(i-1,j,h,w) ) {
                    if( 0 <= next_diff1 && next_diff1 < 10000 ) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][ next_diff1 ];
                    if( 0 <= next_diff2 && next_diff2 < 10000 ) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][ next_diff2 ];
                }
                if( !outField(i,j-1,h,w) ) {
                    if( 0 <= next_diff1 && next_diff1 < 10000 ) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][ next_diff1 ];
                    if( 0 <= next_diff2 && next_diff2 < 10000 ) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][ next_diff2 ];
                }
            }
        }
    }
    rep(i,10000){
        if( dp[h-1][w-1][i] ) {
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}