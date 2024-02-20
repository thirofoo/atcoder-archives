/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/50461053
 * Submitted at: 2024-02-20 10:14:37
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_e
 * Result: AC
 * Execution Time: 57 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, x; cin >> n >> x;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    vector<vector<mint>> dp(x+2,vector<mint>(2,0));
    // dp[i][j] : 時刻 i まで聞いて曲 1 が流れたことがある or ない確率
    mint rev = mint(1) / n;
    dp[0][0] = 1;
    rep(i,x+1) rep(j,2) {
        rep(k,n) {
            ll ni = min(x+1, i+t[k]);
            dp[ni][k==0] += dp[i][j] * rev;
        }
    }
    cout << dp[x+1][1].val() << endl;
    
    return 0;
}