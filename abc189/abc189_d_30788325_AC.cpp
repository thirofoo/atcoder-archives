/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30788325
 * Submitted at: 2022-04-08 17:36:54
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_d
 * Result: AC
 * Execution Time: 8 ms
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
    int n; cin >> n;
    vector<vector<ll>> dp(2,vector<ll>(n+1,0));
    dp[0][0] = 1; dp[1][0] = 1;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        if(s == "AND"){
            dp[0][i] = dp[1][i-1]+dp[0][i-1]*2;
            dp[1][i] = dp[1][i-1];
        }
        else{
            dp[0][i] = dp[0][i-1];
            dp[1][i] = dp[0][i-1]+dp[1][i-1]*2;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}