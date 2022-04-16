/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31017781
 * Submitted at: 2022-04-16 21:15:36
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_c
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,m,k; cin >> n >> m >> k;
    vector<vector<mint>> dp(n,vector<mint>(k,0));
    rep(i,m)dp[0][i] = 1;

    rep(i,n-1){
        rep(j,k){
            for(int l=1;l<=m;l++){
                if(j+l >= k)continue;
                dp[i+1][j+l] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    rep(i,k)ans += dp[n-1][i].val();
    cout << ans.val() << endl;

    return 0;
}