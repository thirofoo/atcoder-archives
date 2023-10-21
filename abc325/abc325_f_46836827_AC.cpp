/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46836827
 * Submitted at: 2023-10-22 00:13:47
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_f
 * Result: AC
 * Execution Time: 144 ms
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
    // dp[i][j] : i個目までみてセンサー1をj個使うときの最小のセンサー2の数
    // ⇒ こうするとコスト計算を dpテーブルを用いて後から推定可能
    ll n; cin >> n;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    ll l1, c1, k1, l2, c2, k2; cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
    vector<vector<ll>> dp(n+1,vector<ll>(k1+1,1e16));
    dp[0][0] = 0;
    rep(i,n) {
        rep(j,k1+1) {
            rep(k,k1+1) {
                if( j+k > k1 ) break;
                dp[i+1][j+k] = min(dp[i+1][j+k], dp[i][j] + max((d[i]-k*l1+l2-1)/l2 ,0ll));
            }
        }
    }
    ll ans = 1e16;
    rep(i,k1+1) {
        if( dp[n][i] > k2 ) continue;
        ans = min(ans, i*c1 + dp[n][i]*c2);
    }
    cout << (ans == 1e16 ? -1 : ans) << endl;
    
    return 0;
}