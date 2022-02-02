/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc099/submissions/29013132
 * Submitted at: 2022-02-03 00:32:22
 * Problem URL: https://atcoder.jp/contests/abc099/tasks/abc099_c
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> dp(100010); 

int main() {
    int n,tmp = 1; cin >> n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        while(tmp*6 <= i){
            tmp *= 6; dp[i] = min(dp[i],dp[i-tmp]+1);
        }
        tmp = 1;
        while(tmp*9 <= i){
            tmp *= 9; dp[i] = min(dp[i],dp[i-tmp]+1);
        }
        tmp = 1;
    }
    cout << dp[n] << endl;
    return 0;
}