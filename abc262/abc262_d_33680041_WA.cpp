/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/33680041
 * Submitted at: 2022-07-31 21:54:37
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_d
 * Result: WA
 * Execution Time: 18 ms
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
    vector<vector<mint>> dp(n+1,vector<mint>(n,0));
    dp[0][0] = 1;
    rep(k,n){
        for(int i=n-1;i>=0;i--){
            rep(j,n){
                dp[i+1][(j+a[i])%n] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(i,n){
        rep(j,n){
            if(j%(i+1) == 0)ans += dp[i+1][j];
        }
    }
    cout << ans.val() << endl;
    return 0;
}