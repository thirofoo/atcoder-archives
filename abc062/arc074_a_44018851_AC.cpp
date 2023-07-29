/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc062/submissions/44018851
 * Submitted at: 2023-07-29 09:11:27
 * Problem URL: https://atcoder.jp/contests/abc062/tasks/arc074_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    // 1つの長方形の1辺は h or w になる
    // → 残り2つは、1つ目の長方形と同方向 or 違方向 で出来るだけ半分にすべき
    ll h,w; cin >> h >> w;
    ll ans = 1e16, r1, r2, r3;

    // 1つ目の長方形の 縦 or 横 全探索
    for(ll i=1;i<h;i++){
        r1 = w*i;
        r2 = (h-i) * (w/2), r3 = h*w - r1 - r2;
        ans = min( ans, max({abs(r1-r2), abs(r1-r3), abs(r2-r3)}) );

        r2 = ((h-i)/2) * w, r3 = h*w - r1 - r2;
        ans = min( ans, max({abs(r1-r2), abs(r1-r3), abs(r2-r3)}) );
    }
    for(ll i=1;i<w;i++){
        r1 = h*i;
        r2 = (w-i) * (h/2), r3 = h*w - r1 - r2;
        ans = min( ans, max({abs(r1-r2), abs(r1-r3), abs(r2-r3)}) );

        r2 = h * ((w-i)/2), r3 = h*w - r1 - r2;
        ans = min( ans, max({abs(r1-r2), abs(r1-r3), abs(r2-r3)}) );
    }
    cout << ans << endl;
    
    return 0;
}