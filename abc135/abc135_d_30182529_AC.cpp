/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc135/submissions/30182529
 * Submitted at: 2022-03-17 16:50:25
 * Problem URL: https://atcoder.jp/contests/abc135/tasks/abc135_d
 * Result: AC
 * Execution Time: 39 ms
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
    string s; cin >> s;
    int size = s.size();
    vector<vector<mint>> dp(size+1,vector<mint>(13,0));
    dp[0][0] = 1;
    for(int i=0;i<size;i++){
        rep(j,13){
            if(s[i] == '?'){
                rep(k,10)dp[i+1][(j*10+k)%13] += dp[i][j];
            }
            else{
                dp[i+1][(j*10+s[i]-'0')%13] += dp[i][j];
            }
        }
    }
    cout << dp[size][5].val() << endl;
    return 0;
}