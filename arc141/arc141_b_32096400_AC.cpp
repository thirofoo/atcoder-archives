/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc141/submissions/32096400
 * Submitted at: 2022-05-30 00:04:06
 * Problem URL: https://atcoder.jp/contests/arc141/tasks/arc141_b
 * Result: AC
 * Execution Time: 24 ms
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
    
    ll n,m; cin >> n >> m;
    if(n > 60)return cout << 0 << endl,0;
    int l = log2(m)+1;
    vector<vector<mint>> dp(n,vector<mint>(l,0));
    rep(i,l){
        dp[0][i] = min((ll)pow(2LL,i+1)-1,m) - ((ll)pow(2LL,i)-1);
    }

    rep(i,n-1){
        rep(j,l-1){
            for(int k=j+1;k<l;k++){
                dp[i+1][k] += dp[i][j]*(min((ll)pow(2LL,k+1)-1,m) - ((ll)pow(2LL,k)-1));
            }
        }
    }

    mint ans = 0;
    rep(i,l)ans += dp[n-1][i];
    cout << ans.val() << endl;

    return 0;
}