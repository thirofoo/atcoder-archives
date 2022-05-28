/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/32045278
 * Submitted at: 2022-05-28 22:15:27
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_e
 * Result: AC
 * Execution Time: 53 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k; cin >> n >> m >> k;
    vector<vector<mint>> dp(n,vector<mint>(m+1,0));
    rep(i,m+1)dp[0][i] = i;

    for(int i=1;i<n;i++){
        for(int j=1;j<m+1;j++){
            if(k == 0){
                dp[i][j] += dp[i-1][m] - dp[i-1][0];
            }
            else{
                dp[i][j] += dp[i-1][m] - dp[i-1][min(j+k-1,m)];
                dp[i][j] += dp[i-1][max(0LL,j-k)] - dp[i-1][0];
            }
        }
        rep(j,m)dp[i][j+1] += dp[i][j];
    }

    cout << dp[n-1][m].val() << endl;

    return 0;
}