/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52121195
 * Submitted at: 2024-04-07 00:16:50
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
    vector<vector<int>> a(m, vector<int>(n));
    rep(i,n) rep(j,m) cin >> a[j][i];

    vector<vector<bool>> ok(n, vector<bool>(n, false));
    rep(i,m) rep(j,n) reps(k,j+1,n) ok[j][k] = (a[i][j] == a[i][k]) ^ ok[j][k];
    int ans = 0;
    rep(i,n) reps(j,i+1,n) ans += ok[i][j];
    cout << ans << '\n';
    
    return 0;
}