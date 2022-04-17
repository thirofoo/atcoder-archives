/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31069223
 * Submitted at: 2022-04-17 22:38:08
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_f
 * Result: AC
 * Execution Time: 767 ms
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
typedef modint mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,p; cin >> n >> p;
    modint::set_mod(p);

    //dp[i][j][k]:縦二つの頂点の集合のうちのi個目までで、状態kでj個の辺を除いた時の場合の数。
    //状態k : 0 -> 頂点集合iの二頂点が未連結。　1 -> 連結とする。
    vector<vector<vector<mint>>> dp(n,vector<vector<mint>>(n+5,vector<mint>(2,0)));
    dp[0][0][1] = 1; dp[0][1][0] = 1;

    rep(i,n-1){
        rep(j,n){
            //i-1の状態が未連結(k=0)の時。
            dp[i+1][j+1][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][0];

            //i-1の状態が連結(k=1)の時。
            dp[i+1][j+2][0] += dp[i][j][1]*2;
            dp[i+1][j+1][1] += dp[i][j][1]*3;
            dp[i+1][j][1] += dp[i][j][1];
        }
    }

    rep(i,n-1)cout << dp[n-1][i+1][1].val() << " ";
    cout << endl;
    return 0;
}