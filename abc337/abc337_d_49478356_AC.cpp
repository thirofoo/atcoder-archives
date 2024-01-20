/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49478356
 * Submitted at: 2024-01-20 21:39:30
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_d
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans = 1e9;
    // 横になぞって連続 K の時を探索
    if( k <= w ) {
        // x が出た瞬間そこでリセット
        rep(i,h) {
            ll maru = 0, dot = 0;
            rep(j,w) {
                if( s[i][j] == 'x' ) {
                    maru = 0;
                    dot = 0;
                }
                else {
                    if( s[i][j] == 'o' ) maru++;
                    else dot++;
                }
                // 連続 K の時
                if( maru + dot == k ) {
                    ans = min(ans, dot);
                    // 巻き戻し
                    if( s[i][j-k+1] == 'o' ) maru--;
                    else dot--;
                }
            }
        }
    }
    // 縦になぞって連続 K の時を探索
    if( k <= h ) {
        // x が出た瞬間そこでリセット
        rep(j,w) {
            ll maru = 0, dot = 0;
            rep(i,h) {
                if( s[i][j] == 'x' ) {
                    maru = 0;
                    dot = 0;
                }
                else {
                    if( s[i][j] == 'o' ) maru++;
                    else dot++;
                }
                // 連続 K の時
                if( maru + dot == k ) {
                    ans = min(ans, dot);
                    // 巻き戻し
                    if( s[i-k+1][j] == 'o' ) maru--;
                    else dot--;
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}