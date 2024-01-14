/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49306308
 * Submitted at: 2024-01-14 21:57:22
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_e
 * Result: AC
 * Execution Time: 970 ms
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
    
    ll n; cin >> n;
    // 桁和は max 126 (=9*14)
    // ⇒ 桁和 = 1~126 全てにおいて桁DP -> その結果から約数包除原理で答えを求める？

    // 桁数取得
    ll dig = 0, tmp = n;
    while(tmp > 0) {
        dig++;
        tmp /= 10;
    }
    // cerr << "dig : " << dig << endl;

    ll ans = 0;
    for(ll M=1; M<=126; M++) {
        // dp[i][j][k][l] : i 桁目まで見て桁和 j (M以上なら M+1 にする) で、数字 mod M が k で、n 未満が確定しているかどうか l (0:未満未確定, 1:未満確定)
        vector<vector<vector<vector<ll>>>> dp(dig+1, vector<vector<vector<ll>>>(M+2, vector<vector<ll>>(M, vector<ll>(2, 0))));
        dp[0][0][0][0] = 1;
        rep(i,dig) {
            rep(j,M+1) {
                rep(k,M) {
                    rep(l,2) {
                        ll lim = 9;
                        if( l == 0 ) lim = (n / (ll)pow(10, dig-i-1)) % 10;
                        rep(m,lim+1) {
                            ll nl = l;
                            if( l == 0 && m < lim ) nl = 1;
                            ll nj = j + m;
                            if( nj >= M+1 ) nj = M+1;
                            ll nk = (k*10+m) % M;
                            dp[i+1][nj][nk][nl] += dp[i][j][k][l];
                        }
                    }
                }
            }
        }
        ans += dp[dig][M][0][0] + dp[dig][M][0][1];
        // cerr << M << " : " << ans << endl;
    }
    cout << ans << endl;
    
    return 0;
}