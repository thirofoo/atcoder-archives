/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45799992
 * Submitted at: 2023-09-23 01:01:40
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
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
uint D[15][15];
uint bitDP[1 << 15][15];
uint up[15], down[15];
uint n, i, j, state, n_state, N, res, u, v, s, s_up, s_down;


int main(void){
    n = get(); if(n <= 2){puts("0 0"); return 0;}
    for(i = 0; i < n; ++i){
        for(j = i + 1; j < n; ++j){ D[i][j] = get(); D[j][i] = D[i][j]; }
    }
    n--;
    N = 1 << n;
    for(state = 1; state < N; ++state) for(i = 0; i < n; ++i) bitDP[state][i] = inf;
    for(i = 0, state = 1; i < n; ++i, state <<= 1) bitDP[state][i] = D[i][n];

    for(state = 1; state < N; ++state){
        s = state; s_up = 0, s_down = 0;
        for(i = 0; i < n; ++i, s >>= 1) ((s & 1) ? up[s_up++] : down[s_down++]) = i;
        for(j = 0, v = down[0]; j < s_down; v = down[++j]){
            n_state = state | (1U << v);
            for(i = 0, u = up[0]; i < s_up; u = up[++i]){
                const uint&& tmp = bitDP[state][u] + D[u][v];
                if(tmp < bitDP[n_state][v]) bitDP[n_state][v] = tmp;
            }
        }
    }
    res = inf;
    for(uint i = 0; i < n; ++i){
        const uint&& tmp = bitDP[N - 1][i] + D[i][n]; if(res > tmp) res = tmp;
    }
    printf("%u %u\n", n + 1, res);
    return 0;
}