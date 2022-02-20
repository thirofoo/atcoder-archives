/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/29521571
 * Submitted at: 2022-02-20 21:18:23
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_c
 * Result: AC
 * Execution Time: 9 ms
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

int main() {
    int n,x; cin >> n >> x;
    vector<vector<bool>> dp(n+1,vector<bool>(10100,false));
    dp[0][0] = true;
    rep(i,n){
        int a,b; cin >> a >> b;
        rep(j,10000){
            if(dp[i][j]){
                if(j+a <= 10000)dp[i+1][j+a] = true;
                if(j+b <= 10000)dp[i+1][j+b] = true;
            }
        }
    }
    
    if(dp[n][x])cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}