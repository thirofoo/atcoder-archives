/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45799722
 * Submitted at: 2023-09-23 00:38:49
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,fma,abm,mmx,avx,avx2")
using uint = unsigned int;

uint g[15][15];
uint dp[1 << 15][15];
uint lj[15], lk[15];
uint res = 1e9, ji, ki, i, j, k, i1, i2, n, N;
uint &&K = 0;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
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
    N = (1 << n), K;
    for (i=1; i<N; i++) for (int j=0; j<n; j++) dp[i][j] = 1000000000;

    // bitDP
    dp[1][0] = 0;
    for (i=1; i<N; i++) {
        ji = 0, ki = 0;
        for (j=0; j<n; j++) {
            if( i & 1 << j ) lj[ji++] = j;
            else lk[ki++] = j;
        }

        for (k=lk[0], i2=1; i2<=ki; k=lk[i2++]) {
            K = i | 1 << k;
            for (j=lj[0], i1=1; i1<=ji; j=lj[i1++]) {
                dp[K][k] = min(dp[K][k], dp[i][j] + g[k][j]);
            }
        }
    }
    for(i=0;i<n;i++) res = min(res, dp[N-1][i] + g[i][0]);
    cout << n << " " << res << '\n';

    return 0;
}