/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46963314
 * Submitted at: 2023-10-27 16:53:54
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc247_e
 * Result: AC
 * Execution Time: 11 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x, y, i; cin >> n >> x >> y;
    vector<int> a(n);
    for(i=0; i<n; i++) cin >> a[i];
    int sx = -1, sy = -1, b = -1;
    long long ans = 0;
    for(i=0; i<n; i++) {
        if( a[i] < y || x < a[i] ) sx = i, sy = i, b = i;
        else {
            if( a[i] == x ) sx = i;
            if( a[i] == y ) sy = i;
        }
        ans += min(sx, sy) - b;
    }
    cout << ans << '\n';
    
    return 0;
}