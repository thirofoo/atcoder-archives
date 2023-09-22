/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45789811
 * Submitted at: 2023-09-22 16:36:07
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;

uint g[15][15];
uint dp[1 << 15][15];
uint res = 1e9;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    uint n; cin >> n;
    if( n == 2 ) {
        cout << "0 0" << '\n';
        return 0;
    }

    for (uint i=0; i<n-1; i++) {
        for (uint j=i+1; j<n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    uint N = (1 << n), K;
    for (uint i=1; i<N; i++) for (uint j=0; j<n; j++) dp[i][j] = 1e9;

    // bitDP
    dp[1][0] = 0;
    for (uint i=1; i<N; i++) {
        for (uint j=0; j<n; j++) {
            for (uint k=0; k<n; k++) {
                K = 1 << k;
                if( i & K ) continue;
                K = i | K;
                dp[K][k] = min(dp[K][k], dp[i][j] + g[j][k]);
                if( K == N - 1 ) res = min(res, dp[K][k] + g[k][0]);
            }
        }
    }
    cout << n << " " << res << '\n';

    return 0;
}