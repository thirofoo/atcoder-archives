/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29180197
 * Submitted at: 2022-02-09 18:19:05
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_i
 * Result: AC
 * Execution Time: 91 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<vector<double>> dp(3005,vector<double>(3005,0));

int main() {
    cout << setprecision(10);
    int n; cin >> n;
    dp[1][1] = 1;
    for(int i=1;i<=n;i++){
        double p; cin >> p;
        for(int j=0;j<=i;j++){
            if(j+1 <= n+1 && i+1-j <= n+1){
                dp[j+1][i+1-j] = dp[j][i+1-j]*p + dp[j+1][i-j]*(1-p);
            }
        }
    }
    double ans = 0;
    for(int i=n+1;i>n/2+1;i--){
        ans += dp[i][n+2-i];
    }
    cout << ans << endl;
    return 0;
}