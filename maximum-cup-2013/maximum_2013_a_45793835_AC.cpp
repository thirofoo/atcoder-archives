/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45793835
 * Submitted at: 2023-09-22 20:12:05
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 11 ms
 */

#include <bits/stdc++.h>
using namespace std;

int g[15][15];
int dp[1 << 15][15];
int lj[15], lk[15];
int res = 1e9, ji, ki, i, j, k, i1, i2;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    if( n == 2 ) {
        cout << "0 0" << '\n';
        return 0;
    }

    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    int N = (1 << n), K;
    for (i=1; i<N; i++) for (int j=0; j<n; j++) dp[i][j] = 1e9;

    // bitDP
    dp[1][0] = 0;
    for (i=1; i<N; i++) {
        ji = 0, ki = 0;
        for (j=0; j<n; j++) {
            if( i & 1 << j ) lj[ji++] = j;
            else lk[ki++] = j;
        }
        lj[ji] = '\0', lk[ki] = '\0';

        for(auto &&k:lk) {
            K = i | 1 << k;
            for(auto &&j:lj) {
                dp[K][k] = min(dp[K][k], dp[i][j] + g[j][k]);
            }
        }
    }
    for(int i=0;i<n;i++) res = min(res, dp[N-1][i] + g[i][0]);
    cout << n << " " << res << '\n';

    return 0;
}