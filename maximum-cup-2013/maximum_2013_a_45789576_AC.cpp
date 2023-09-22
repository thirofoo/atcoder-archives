/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45789576
 * Submitted at: 2023-09-22 16:25:31
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    if( n == 2 ) {
        cout << "0 0" << '\n';
        return 0;
    }

    vector g(n,vector<int>(n,{}));
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }

    // bitDP
    vector dp(1 << n,vector<int>(n,1e9));
    int res = 1e9;
    dp[1][0] = 0;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if( i & 1 << k ) continue;
                dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + g[j][k]);
                if( (i | 1 << k) == (1 << n) - 1 ) res = min(res, dp[i | 1 << k][k] + g[k][0]);
            }
        }
    }
    cout << n << " " << res << '\n';

    return 0;
}