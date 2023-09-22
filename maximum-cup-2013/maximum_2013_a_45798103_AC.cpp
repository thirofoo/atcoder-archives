/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45798103
 * Submitted at: 2023-09-22 23:05:52
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
        for (j=0; j<n; j++) ( i & 1 << j ? lj[ji++] : lk[ki++] ) = j;
        for (k=lk[0], i2=1; i2<=ki; k=lk[i2++]) {
            K = i | 1 << k;
            for (j=lj[0], i1=1; i1<=ji; j=lj[i1++]) {
                dp[K][k] = min(dp[K][k], dp[i][j] + g[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++) res = min(res, dp[N-1][i] + g[i][0]);
    cout << n << " " << res << '\n';

    return 0;
}