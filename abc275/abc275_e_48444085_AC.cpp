/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/48444085
 * Submitted at: 2023-12-12 15:55:02
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_e
 * Result: AC
 * Execution Time: 1044 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// ※ AtCoderのコードテスト上だと動きます
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    vector dp(k+1,vector<mint>(n+1,0));
    dp[0][0] = 1;
    for(ll i=0; i<k; i++) {
        // Goal したらその時点で終了 ⇒ N は含まない
        for(ll j=0; j<n; j++) {
            for(ll t=1; t<=m; t++) {
                if( j+t <= n ) dp[i+1][j+t] += dp[i][j]/m;
                else dp[i+1][n-(t-(n-j))] += dp[i][j]/m;
            }
        }
    }
    mint ans = 0;
    for(ll i=1; i<=k; i++) ans += dp[i][n];
    cout << ans.val() << endl;
    return 0;
}