/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/50040416
 * Submitted at: 2024-02-05 22:00:14
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_f
 * Result: AC
 * Execution Time: 29 ms
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
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    // dp[i][j][k][l] : i 番目まで見て, LIS = {j,k,l} の場合の数
    vector dp(n+1,vector(m+2,vector(m+2,vector<mint>(m+2,0))));
    dp[0][m+1][m+1][m+1] = 1;
    rep(i,n) reps(j,1,m+2) reps(k,1,m+2) reps(l,1,m+2) {
        reps(to,1,m+1) {
            ll nj = j, nk = k, nl = l;
            if( to <= j ) nj = to;
            else if( to <= k ) nk = to;
            else if( to <= l ) nl = to;
            else continue;
            dp[i+1][nj][nk][nl] += dp[i][j][k][l];
        }
    }
    mint ans = 0;
    reps(j,1,m+1) reps(k,j+1,m+1) reps(l,k+1,m+1) ans += dp[n][j][k][l];
    cout << ans.val() << endl;
    
    return 0;
}