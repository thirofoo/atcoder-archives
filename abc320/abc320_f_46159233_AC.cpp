/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc320/submissions/46159233
 * Submitted at: 2023-10-02 16:32:23
 * Problem URL: https://atcoder.jp/contests/abc320/tasks/abc320_f
 * Result: AC
 * Execution Time: 160 ms
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
    
    // 解説AC
    // 行き帰りで密接に関わってるのだるい
    // ⇒ 一緒のタイミングで管理しちゃえば ok
    ll n, h; cin >> n >> h;
    vector<ll> x(n+1,0), p(n-1), f(n-1);
    rep(i,n) cin >> x[i+1];
    rep(i,n-1) cin >> p[i] >> f[i];
    vector dp(n+1,vector<vector<ll>>(h+1,vector<ll>(h+1,1e16)));
    dp[0][h][0] = 0;
    // dp[i][j][k] : i個目のガソスタを見て、行きでjL保持、帰りでkL消費する時の最小コスト
    rep(i,n) {
        ll d = x[i+1]-x[i];
        rep(j,h+1) {
            // そもそも次に行けない時
            if( j-d < 0 ) continue;
            rep(k,h+1) {
                // 必要なガソリン量が容量オーバーの時
                if( k+d > h ) continue;

                // ガソスタ未使用
                dp[i+1][j-d][k+d] = min(dp[i+1][j-d][k+d], dp[i][j][k]);

                if( i == n-1 ) continue;
                // 行きdeガソスタ使用
                dp[i+1][min(h,j-d+f[i])][k+d] = min(dp[i+1][min(h,j-d+f[i])][k+d], dp[i][j][k] + p[i]);

                // 返りdeガソスタ使用
                dp[i+1][j-d][max(0ll,k+d-f[i])] = min(dp[i+1][j-d][max(0ll,k+d-f[i])], dp[i][j][k] + p[i]);
            }
        }
    }
    ll ans = 1e16;
    rep(i,h+1) {
        rep(j,h+1) {
            if( i < j ) continue;
            ans = min(ans, dp[n][i][j]);
        }
    }
    cout << (ans == 1e16 ? -1 : ans) << endl;
    
    return 0;
}