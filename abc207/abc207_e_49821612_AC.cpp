/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc207/submissions/49821612
 * Submitted at: 2024-01-31 02:46:49
 * Problem URL: https://atcoder.jp/contests/abc207/tasks/abc207_e
 * Result: AC
 * Execution Time: 143 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

#define COLOR_CNT 3
const vector<vector<ll>> c_idx = {{1,2},{0,2},{0,1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC
    // dp の 3 次元目に総和を入れないと駄目かと思ったが、今いる場から連続して前に戻って計算すれば良い
    // ⇒ 累積和を用いれば O(N^3) で遷移まで書ける
    // ⇒ 過去の DP を memo 化しておけば遷移 O(N) ⇒ O(1) で済み O(N^2)

    ll n; cin >> n;
    vector<ll> a(n+1,0);
    rep(i,n) cin >> a[i+1];
    rep(i,n) a[i+1] += a[i];
    // dp[j][k] : i 個目まで見て, j 個目の集合の場合の数
    // memo[i][j] : 歴代の sum mod i ≡ j となる過去の DP の結果の memo
    vector<vector<mint>> dp(n+1,vector<mint>(n+1,0)), memo(n+1, vector<mint>(n+1,0));
    dp[0][0] = 1, memo[1][0] = 1;
    for(ll i=1; i<=n; i++) {
        // for(ll j=1; j<=n; j++) {
        //     for(ll k=0; k<i; k++) {
        //         if( (a[i]-a[k])%j != 0 ) continue;
        //         dp[i][j] += dp[k][j-1];
        //     }
        // }
        for(ll j=1; j<=n; j++) dp[i][j] = memo[j][a[i]%j];
        // dp[i][j] の時の遷移は j-1 個目の集合まで出来てる想定なので dp[i][j-1] から memo 化
        for(ll j=1; j<=n; j++) memo[j][a[i]%j] += dp[i][j-1];
    }
    mint ans = 0;
    for(ll i=1; i<=n; i++) ans += dp[n][i];
    cout << ans.val() << endl;
    
    return 0;
}