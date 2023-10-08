/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc166/submissions/46382118
 * Submitted at: 2023-10-08 21:46:52
 * Problem URL: https://atcoder.jp/contests/arc166/tasks/arc166_b
 * Result: AC
 * Execution Time: 349 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, a, b, c; cin >> n;
    vector<ll> A(n), abc(3);
    rep(i,3) cin >> abc[i];
    rep(i,n) cin >> A[i];
    // bitDP風にやる
    vector dp(n+1,vector<ll>(1 << 3,1e18));
    dp[0][0] = 0;
    rep(i,n) {
        rep(j,1 << 3) {
            if( dp[i][j] >= 1e18 ) continue;
            rep(k,1 << 3) {
                ll lcm = 1;
                rep(l,3) if( k & (1 << l) ) lcm = lcm*abc[l]/gcd(lcm,abc[l]);
                dp[i+1][j|k] = min(dp[i+1][j|k], dp[i][j]+ lcm-(A[i]%lcm + (A[i]%lcm == 0 ? lcm : 0)) );
            }
        }
    }
    // rep(i,n+1) {
    //     rep(j,1 << 3) cerr << dp[i][j] << " ";
    //     cerr << endl;
    // }
    cout << dp[n][(1 << 3)-1] << endl;
    
    return 0;
}