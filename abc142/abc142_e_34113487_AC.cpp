/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc142/submissions/34113487
 * Submitted at: 2022-08-18 00:15:35
 * Problem URL: https://atcoder.jp/contests/abc142/tasks/abc142_e
 * Result: AC
 * Execution Time: 63 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> dp(1LL << n,vector(m+1,LLONG_MAX));
    dp[0][0] = 0;
    rep(j,m){
        ll a,b,now = 0; cin >> a >> b;
        rep(i,b){
            ll tmp; cin >> tmp;
            now |= (1LL << (tmp-1));
        }
        rep(i,1LL << n){
            if(dp[i][j] == LLONG_MAX)continue;
            dp[now | i][j+1] = min(dp[now | i][j+1],dp[i][j]+a);
            dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
        }
    }
    cout << (dp[(1LL << n)-1][m] == LLONG_MAX ? -1 : dp[(1LL << n)-1][m]) << endl;
    
    return 0;
}