/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50922482
 * Submitted at: 2024-03-05 17:31:19
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_e
 * Result: AC
 * Execution Time: 349 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, b, K; cin >> n >> b >> K;
    vector<ll> c(K);
    rep(i, K) cin >> c[i];
    // 繰り返し二乗法みたいに dp テーブルを用意すれば行けるのでは？
    // dp[i][j] : 2^i 桁で B で割った余りが j になるような場合の数
    vector<vector<mint>> dp;
    vector<mint> first_dp(b,0);
    rep(i, K) first_dp[c[i]%b]++;
    dp.emplace_back(first_dp);

    const ll r_max = 62;
    vector<ll> r10(r_max+1,1); // 10^{2^i} mod b
    r10[1] = 10%b;
    reps(i,1,r_max) r10[i+1] = (r10[i]*r10[i])%b;

    rep(i,r_max) {
        vector<mint> next_dp(b,0);
        rep(j, b) rep(k, b) next_dp[(j*r10[i+1]+k)%b] += dp[i][j]*dp[i][k];
        dp.emplace_back(next_dp);
    }
    
    vector<mint> ans = dp[0]; n--;
    rep(i, r_max) {
        if( !(n & (1ll << i)) ) continue;
        vector<mint> next_ans(b,0);
        rep(j, b) rep(k, b) next_ans[(j*r10[i+1]+k)%b] += ans[j]*dp[i][k];
        swap(ans, next_ans);
    }
    cout << ans[0].val() << endl;
    
    return 0;
}