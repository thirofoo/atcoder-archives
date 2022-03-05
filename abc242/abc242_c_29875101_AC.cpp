/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/29875101
 * Submitted at: 2022-03-05 21:12:07
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_c
 * Result: AC
 * Execution Time: 119 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<vector<mint>> dp(n,vector<mint>(9,0));
    rep(i,9)dp[0][i] = 1;
    for(int i=1;i<n;i++){
        rep(j,9){
            dp[i][j] += dp[i-1][j];
            if(j != 0)dp[i][j] += dp[i-1][j-1];
            if(j != 8)dp[i][j] += dp[i-1][j+1];
        }
    }
    mint ans = 0;
    rep(i,9)ans += dp[n-1][i];
    cout << ans.val() << endl;
    return 0;
}