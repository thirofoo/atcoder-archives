/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29936807
 * Submitted at: 2022-03-07 18:18:02
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_i
 * Result: AC
 * Execution Time: 93 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << fixed << setprecision(10);
    int n; cin >> n;
    vector<double> p(n);
    rep(i,n)cin >> p[i];
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            dp[i-j][j+1] += dp[i-j][j]*p[i];
            dp[i-j+1][j] += dp[i-j][j]*(1-p[i]);
        }
    }

    double ans = 0;
    rep(i,n+1){
        if(n-i > i)ans += dp[i][n-i];
    }
    cout << ans << '\n';
    return 0;
}