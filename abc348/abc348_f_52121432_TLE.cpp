/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52121432
 * Submitted at: 2024-04-07 00:24:02
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_f
 * Result: TLE
 * Execution Time: 2208 ms
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, l, r) for(int i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    int ans = 0;
    rep(i,n) reps(j,i+1,n) {
        int c = 0;
        rep(k,m) c += (a[i][k] == a[j][k]);
        ans += (c & 1);
    }
    cout << ans << '\n';
    
    return 0;
}