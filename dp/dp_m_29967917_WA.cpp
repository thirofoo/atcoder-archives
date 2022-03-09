/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/29967917
 * Submitted at: 2022-03-09 15:39:08
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_m
 * Result: WA
 * Execution Time: 156 ms
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

int mod = 1000000007;

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(k+2,0));
    dp[0][0] = 1; dp[0][1] = -1;
    ll cnt = 0;
    rep(i,n){
        rep(j,k+2){
            cnt += dp[i][j];
            if(cnt){
                dp[i+1][j] += cnt;
                dp[i+1][(j+a[i]+1 >= k+2 ? k+1 : j+a[i]+1)] -= cnt;
            }
        }
        //いもす法
        rep(j,k+1){
            dp[i][j+1] += dp[i][j];
            dp[i][j] %= mod;
        }
    }

    //いもす法
    rep(j,k+1){
        dp[n][j+1] += dp[n][j];
        dp[n][j] %= mod;
    }

    cout << dp[n][k] << endl;
    return 0;
}