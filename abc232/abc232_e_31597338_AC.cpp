/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/31597338
 * Submitted at: 2022-05-11 13:06:53
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_e
 * Result: AC
 * Execution Time: 104 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef modint998244353 mint;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int h,w,k,x1,y1,x2,y2; cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    vector<vector<mint>> dp(k+1,vector<mint>(4,0));
    int tmp = 0;
    if(x1 == x2 && y1 == y2)tmp = 3;
    else if(x1 == x2)tmp = 2;
    else if(y1 == y2)tmp = 1;
    dp[0][tmp] = 1;
    rep(i,k){
        rep(j,4){
            if(j == 0){
                dp[i+1][0] += (w+h-4)*dp[i][j];;
                dp[i+1][1] += dp[i][j];
                dp[i+1][2] += dp[i][j];
            }
            else if(j == 1){
                dp[i+1][0] += (w-1)*dp[i][j];
                dp[i+1][1] += (h-2)*dp[i][j];
                dp[i+1][3] += dp[i][j];
            }
            else if(j == 2){
                dp[i+1][0] += (h-1)*dp[i][j];
                dp[i+1][2] += (w-2)*dp[i][j];
                dp[i+1][3] += dp[i][j];
            }
            else{
                dp[i+1][1] += (h-1)*dp[i][j];
                dp[i+1][2] += (w-1)*dp[i][j];
            }
        }
    }

    cout << dp[k][3].val() << endl;

    return 0;
}