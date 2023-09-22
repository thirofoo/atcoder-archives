/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45796061
 * Submitted at: 2023-09-22 21:41:40
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

int g[15][15];
int dp[1 << 15][15];
int lj[15], lk[15];
int res = 1e9, ji, ki, i, j, k, i1, i2;

int main() {
    int n; scanf("%d",&n);
    if( n == 2 ) return printf("0 0\n"), 0;

    for (i=0; i<n-1; i++) {
        for (j=i+1; j<n; j++) {
            scanf("%d",&g[i][j]);
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
        
        for (k=lk[0], i2=1; i2<=ki; k=lk[i2++]) {
            K = i | 1 << k;
            for (j=lj[0], i1=1; i1<=ji; j=lj[i1++]) {
                const int&& tmp = dp[i][j] + g[k][j];
                if( dp[K][k] > tmp ) dp[K][k] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        const int&& tmp = dp[N-1][i] + g[i][0];
        if( res > tmp ) res = tmp;
    }
    printf("%d %d\n", n, res);

    return 0;
}