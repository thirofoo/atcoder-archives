/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/33688304
 * Submitted at: 2022-07-31 22:36:59
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_d
 * Result: AC
 * Execution Time: 413 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    vector<vector<vector<mint>>> dp(n+1,vector<vector<mint>>(n+1,vector<mint>(n,0)));
    rep(i,n)dp[i+1][0][0] = 1;
    mint ans = 0;
    for(int k=1;k<=n;k++){
        rep(l,n){
            for(int i=n-1;i>=0;i--){
                rep(j,k){
                    dp[k][i+1][(j+a[l])%k] += dp[k][i][j];
                }
            }
        }
        ans += dp[k][k][0];
    }
    cout << ans.val() << endl;
    return 0;
}