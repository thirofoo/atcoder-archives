/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46963204
 * Submitted at: 2023-10-27 16:49:33
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc247_e
 * Result: WA
 * Execution Time: 12 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, x, y, i; cin >> n >> x >> y;
    vector<int> a(n);
    for(i=0; i<n; i++) cin >> a[i];
    int ans = 0, sx = -1, sy = -1, b = -1;
    for(i=0; i<n; i++) {
        if( a[i] < y || x < a[i] ) sx = -1, sy = -1, b = i;
        else {
            if( a[i] == x ) sx = i;
            if( a[i] == y ) sy = i;
        }
        if( sx != -1 && sy != -1 ) ans += min(sx, sy) - b;
    }
    cout << ans << endl;
    
    return 0;
}