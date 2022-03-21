/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30321004
 * Submitted at: 2022-03-21 14:27:21
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_h
 * Result: AC
 * Execution Time: 15 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; string s,at = "atcoder"; cin >> n >> s;
    int size = s.size();
    vector<vector<mint>> dp(8,vector<mint>(size+1,0));
    rep(i,size+1)dp[0][i] = 1;
    for(int i=1;i<8;i++){
        for(int j=1;j<size+1;j++){
            dp[i][j] += dp[i][j-1];
            if(at[i-1] == s[j-1])dp[i][j] += dp[i-1][j-1];
        }
    }
    cout << dp[7][size].val() << endl;

    return 0;
}