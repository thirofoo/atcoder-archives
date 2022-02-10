/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/29191890
 * Submitted at: 2022-02-10 11:30:01
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_d
 * Result: AC
 * Execution Time: 34 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<mint>> dp(100005,vector<mint>(10));

int main() {
    int n,first; cin >> n >> first;
    dp[0][first] = 1;
    rep(i,n-1){
        int a; cin >> a;
        rep(j,10){
            dp[i+1][(j+a)%10] += dp[i][j];
            dp[i+1][(j*a)%10] += dp[i][j];
        }
    }
    rep(i,10)cout << dp[n-1][i].val() << endl;
    return 0;
}