/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31060695
 * Submitted at: 2022-04-17 15:44:54
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_c
 * Result: AC
 * Execution Time: 6 ms
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
#define rep(i, n) for(int i = 0; i < n; i++)

int mod = 998244353;

int main() {
    //累積和を用いて区緩和を求め、貰うdpで書くver。
    int n,m,k; cin >> n >> m >> k;
    vector<vector<mint>> dp(n,vector<mint>(k+1,0));
    rep(i,k){
        if(i+1 <= m)dp[0][i+1]++;
        dp[0][i+1] += dp[0][i];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<k+1;j++){
            dp[i][j] += (dp[i-1][j-1].val()-dp[i-1][(j-m-1 < 0 ? 0 : j-m-1)].val()+mod)%mod;
            dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[n-1][k].val() << endl;

    return 0;
}