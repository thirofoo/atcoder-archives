/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc211/submissions/29175157
 * Submitted at: 2022-02-09 12:21:54
 * Problem URL: https://atcoder.jp/contests/abc211/tasks/abc211_c
 * Result: WA
 * Execution Time: 13 ms
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
    string s,cho = "chokudai"; cin >> s;
    vector<vector<int>> dp(9,vector<int>(s.size()+5,0));
    rep(i,s.size()+1)dp[0][i] = 1;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=s.size();j++){  
            dp[i][j] += dp[i][j-1];
            if(cho[i-1] == s[j-1])dp[i][j] += dp[i-1][j-1];
        }
    }
    cout << dp[8][s.size()] << endl;
    return 0;
}