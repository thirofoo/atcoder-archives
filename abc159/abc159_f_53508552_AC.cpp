/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/53508552
 * Submitted at: 2024-05-16 00:56:23
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_f
 * Result: AC
 * Execution Time: 449 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC
    // 連続部分列は状態として、区間未選択・左端選択・左右選択の 3 状態で持てる
    // ⇒ それをもって dp

    ll n, s; cin >> n >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector dp(n+1,vector(s+1,vector<mint>(3,0)));
    dp[0][0][0] = 1;
    rep(i,n) rep(j,s+1) rep(k,3) {
        // 状態延長の遷移
        dp[i+1][j][k] += dp[i][j][k];
        if( k == 1 && j+a[i] <= s ) dp[i+1][j+a[i]][k] += dp[i][j][k];

        // 区間の節目を持つ遷移 (半開区間)
        if( k == 0 ) {
            dp[i+1][j][k+1] += dp[i][j][k];
            if( j+a[i] <= s ) dp[i+1][j+a[i]][k+1] += dp[i][j][k];
        }
        if( k == 1 ) dp[i+1][j][k+1] += dp[i][j][k];
    }
    cout << ( dp[n][s][1] + dp[n][s][2] ).val() << endl;
    
    return 0;
}