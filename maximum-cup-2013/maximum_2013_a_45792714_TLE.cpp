/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/maximum-cup-2013/submissions/45792714
 * Submitted at: 2023-09-22 19:01:50
 * Problem URL: https://atcoder.jp/contests/maximum-cup-2013/tasks/maximum_2013_a
 * Result: TLE
 * Execution Time: 2317 ms
 */

#include <bits/stdc++.h>
using namespace std;

int g[15][15];
int dp[1 << 15][15];
int res = 1e9, n, i;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
     cin >> n;
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
    int N = (1 << n), I;
    for (int i=1; i<N; i++) for (int j=0; j<n; j++) dp[i][j] = 1e9;

    // bitDP
    dp[1][0] = 0;
    vector<vector<int>> todo(1 << 15,vector<int>{});
    todo[1].emplace_back(0);
    for (i=1; i<N; i++) {
        for(auto &&j:todo[i]) {
            for (uint k=0; k<n; k++) {
                if( i & 1 << k ) continue;
                I = i | 1 << k;
                dp[I][k] = min(dp[I][k], dp[i][j] + g[j][k]);
                todo[I].emplace_back(k);
            }
        }
    }
    for(int i=0;i<n;i++) res = min(res, dp[N-1][i] + g[i][0]);
    cout << n << " " << res << '\n';

    return 0;
}