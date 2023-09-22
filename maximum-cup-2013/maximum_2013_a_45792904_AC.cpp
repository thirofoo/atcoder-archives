/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45792904
 * Submitted at: 2023-09-22 19:14:36
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;

int g[15 * 15];
int dp[15 * (1 << 15)];
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
            cin >> g[i*n+j];
            g[j*n+i] = g[i*n+j];
        }
    }
    int N = (1 << n), I, next_I;
    for (int i=1; i<N; i++) for (int j=0; j<n; j++) dp[i*n+j] = 1e9;

    // bitDP
    dp[n] = 0;
    for (uint i=1; i<N; i++) {
        for (uint j=0; j<n; j++) {
            I = i*n + j;
            if( dp[I] == 1e9 ) continue;
            for (uint k=0; k<n; k++) {
                if( i & 1 << k ) continue;
                next_I = (i | 1 << k)*n + k;
                dp[next_I] = min(dp[next_I], dp[I] + g[j*n+k]);
            }
        }
    }
    for(int i=0;i<n;i++) res = min(res, dp[(N-1)*n+i] + g[n*i]);
    cout << n << " " << res << '\n';

    return 0;
}