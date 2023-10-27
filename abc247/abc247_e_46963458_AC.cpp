/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/46963458
 * Submitted at: 2023-10-27 17:00:37
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x, y, a; cin >> n >> x >> y;
    int sx = -1, sy = -1, b = -1;
    long long ans = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if( a == x ) sx = i;
        if( a == y ) sy = i;
        if( a < y || x < a ) sx = i, sy = i, b = i;
        ans += min(sx, sy) - b;
    }
    cout << ans << '\n';
    
    return 0;
}