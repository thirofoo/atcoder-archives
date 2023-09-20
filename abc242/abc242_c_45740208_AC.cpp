/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/45740208
 * Submitted at: 2023-09-20 09:40:54
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_c
 * Result: AC
 * Execution Time: 75 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<mint>> dp(n,vector<mint>(9,0));
    rep(i,9) dp[0][i] = 1;
    for(ll i=1;i<n;i++) {
        rep(j,9) {
            for(ll k=-1;k<=1;k++) {
                if( j+k < 0 || j+k >= 9 ) continue;
                dp[i][j] += dp[i-1][j+k];
            }
        }
    }
    mint ans = 0;
    rep(i,9) ans += dp[n-1][i];
    cout << ans.val() << endl;
    
    return 0;
}