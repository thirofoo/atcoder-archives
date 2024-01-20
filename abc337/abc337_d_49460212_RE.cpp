/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49460212
 * Submitted at: 2024-01-20 21:19:30
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_d
 * Result: RE
 * Execution Time: 2211 ms
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
    rep(i,h) {
        // 初期解
        ll renzoku = 0, maru = 0;
        rep(j,k) {
            if( s[i][j] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[i][j] == 'o' ) maru++;
                renzoku++;
            }
        }
        if( renzoku == k ) ans = min(ans, k-maru);
        for(ll j=k; j<w; j++) {
            // 先頭を削除
            if( s[i][j-k] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[i][j-k] == 'o' ) maru--;
                renzoku--;
            }
            // 末尾を追加
            if( s[i][j] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[i][j] == 'o' ) maru++;
                renzoku++;
            }
            if( renzoku == k ) ans = min(ans, k-maru);
        }
    }
    // 縦になぞって連続 K の時を探索
    rep(i,w) {
        // 初期解
        ll renzoku = 0, maru = 0;
        rep(j,k) {
            if( s[j][i] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[j][i] == 'o' ) maru++;
                renzoku++;
            }
        }
        if( renzoku == k ) ans = min(ans, k-maru);
        for(ll j=k; j<h; j++) {
            // 先頭を削除
            if( s[j-k][i] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[j-k][i] == 'o' ) maru--;
                renzoku--;
            }
            // 末尾を追加
            if( s[j][i] == 'x' ) {
                renzoku = 0;
                maru = 0;
            }
            else {
                if( s[j][i] == 'o' ) maru++;
                renzoku++;
            }
            if( renzoku == k ) ans = min(ans, k-maru);
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}