/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46963073
 * Submitted at: 2023-10-27 16:44:07
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc247_e
 * Result: WA
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
    
    // 解説AC 2個目 (天才解法) 
    // a[i] < y || x < a[i] が成り立つ部分で数列を区切る
    // ⇒ 右端全探索 & 左端を縮めていく感じ
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0, sx = -1, sy = -1;
    rep(i,n) {
        if( a[i] < y || x < a[i] ) sx = -1, sy = -1;
        else {
            if( a[i] == x ) sx = i;
            if( a[i] == y ) sy = i;
        }
        if( sx != -1 && sy != -1 ) ans += min(sx, sy) + 1;
    }
    cout << ans << endl;
    
    return 0;
}