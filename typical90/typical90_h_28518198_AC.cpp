/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28518198
 * Submitted at: 2022-01-15 14:37:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_h
 * Result: AC
 * Execution Time: 19 ms
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

ll const mod = 1000000007;

int main() {
    int n; string s,atc = "atcoder"; cin >> n >> s;
    vector<vector<ll>> dp(7,vector<ll>(n,0));
    if(s.find("a") == s.npos) return cout << 0 << endl,0;
    int tmp = s.find("a");
    for(int i=0;i<7;i++){
        for(int j=tmp;j<n;j++){
            if(i == 0 && atc[i] == s[j])dp[i][j]++;
            if(j != n-1){
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= mod;
            }
            if(i != 6 && j != n-1 && atc[i+1] == s[j+1]){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= mod;
            }
        }
    }
    cout << dp[6][n-1] << endl;
    return 0;
}