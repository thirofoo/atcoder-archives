/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46343235
 * Submitted at: 2023-10-07 22:20:13
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_f
 * Result: WA
 * Execution Time: 1 ms
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
    
    ll xa, ya, xb, yb, xc, yc; cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if( xa == xb && xb == xc ) {
        cout << 2 + abs(ya-yb)+1 + abs(yb-yc) << endl;
        return 0;
    }
    if( ya == yb && yb == yc ) {
        cout << 2 + abs(xa-xb)+1 + abs(xb-xc) << endl;
        return 0;
    }

    ll px1 = xb, py1 = yb;
    if( xb > xc ) px1++;
    else if( xb < xc ) px1--;

    if( yb > yc ) py1++;
    else if( yb < yc ) py1--;

    cout << abs(px1-xa)+abs(py1-ya) + abs(px1-xc)+abs(py1-yc)-1 << endl;
    
    return 0;
}