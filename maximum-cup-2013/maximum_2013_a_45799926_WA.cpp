/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45799926
 * Submitted at: 2023-09-23 00:55:58
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: WA
 * Execution Time: 4 ms
 */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,fma,abm,mmx,avx,avx2")
#include <stdio.h>
using uint = unsigned int;

template <class Integer = uint>
inline Integer get(void){
    Integer res = 0;
    int c; while((c = getc_unlocked(stdin) - '0') >= 0){ res = 10 * res + c; }
    return res;
}

constexpr uint inf = 1e9;
uint g[15][15];
uint dp[1 << 15][15];
uint up[15], down[15];
uint state, n_state, i, j, n, N, res, s, s_up, s_down, u, v;
uint &&tmp = 1;

int main(void){
    n = get(); if(n <= 2){puts("0 0"); return 0;}
    for(i = 0; i < n; ++i) for(j = i + 1; j < n; ++j){ g[i][j] = get(); g[j][i] = g[i][j]; }
    n--;
    N = 1 << n;
    for(state = 1; state < N; ++state) for(i = 0; i < n; ++i) dp[state][i] = inf;
    for(i = 0, state = 1; i < n; ++i, state <<= 1) dp[state][i] = g[i][n];

    for(state = 1; state < N; ++state){
        s = state; s_up = 0, s_down = 0;
        for(i = 0; i < n; ++i, s >>= 1) ((s & 1) ? up[s_up++] : down[s_down++]) = i;
        for(j = 0, v = down[0]; j < s_down; v = down[++j]){
            n_state = state | (1U << v);
            for(i = 0, u = up[0]; i < s_up; u = up[++i]){
                tmp = dp[state][u] + g[u][v];
                if(tmp < dp[n_state][v]) dp[n_state][v] = tmp;
            }
        }
    }
    res = inf;
    for(i = 0; i < n; ++i) tmp = dp[N - 1][i] + g[i][n]; if(res > tmp) res = tmp;
    printf("%u %u\n", n + 1, res);
    return 0;
}