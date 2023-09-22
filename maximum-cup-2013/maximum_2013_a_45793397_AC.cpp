/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45793397
 * Submitted at: 2023-09-22 19:47:16
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 13 ms
 */

#include <bits/stdc++.h>
using namespace std;

int g[15][15];
int dp[1 << 15][15];
int res = 1e9;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    if( n == 2 ) {
        cout << "0 0" << '\n';
        return 0;
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    int N = (1 << n), K;
    for (int i=1; i<N; i++) for (int j=0; j<n; j++) dp[i][j] = 1e9;

    // bitDP
    dp[1][0] = 0;
    for (uint i=1; i<N; i++) {
        for (uint j=0; j<n; j++) {
            if( !(i & 1 << j)) continue;
            for (uint k=0; k<n; k++) {
                if( i & 1 << k ) continue;
                K = i | 1 << k;
                dp[K][k] = min(dp[K][k], dp[i][j] + g[j][k]);
            }
        }
    }
    for(int i=0;i<n;i++) res = min(res, dp[N-1][i] + g[i][0]);
    cout << n << " " << res << '\n';

    return 0;
}