/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51104077
 * Submitted at: 2024-03-10 01:52:09
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_f
 * Result: WA
 * Execution Time: 410 ms
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
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> p(n,vector<ll>(n)), r(n,vector<ll>(n-1)), d(n-1,vector<ll>(n));
    rep(i,n) rep(j,n) cin >> p[i][j];
    rep(i,n) rep(j,n-1) cin >> r[i][j];
    rep(i,n-1) rep(j,n) cin >> d[i][j];

    // 解説AC : dp[i][j][k][l] = (i,j) で max(p) = (k,l) となる P(最小回数,所持金)
    vector dp(n,vector(n, vector(n, vector<P>(n, P(1e16,-1)))));
    dp[0][0][0][0] = P(0,0);
    rep(i,n) rep(j,n) rep(k,i+1) rep(l,j+1) {
        auto [cnt, money] = dp[i][j][k][l];
        if( money == -1 ) continue;
        if( i != n-1 ) {
            ll charge = ( d[i][j] > money ? (d[i][j]-money-1) / p[k][l] + 1 : 0 );
            ll n_cnt = cnt + charge + 1;
            ll n_money = money + charge * p[k][l] - d[i][j];

            ll mx = k, my = l;
            if( p[k][l] < p[i+1][j] ) mx = i+1, my = j;

            if( n_cnt < dp[i+1][j][k][l].first || (n_cnt == dp[i+1][j][k][l].first && n_money > dp[i+1][j][k][l].second) ) {
                dp[i+1][j][mx][my] = P(n_cnt, n_money);
            }
        }
        if( j != n-1 ) {
            ll charge = ( r[i][j] > money ? (r[i][j]-money-1) / p[k][l] + 1 : 0 );
            ll n_cnt = cnt + charge + 1;
            ll n_money = money + charge * p[k][l] - r[i][j];

            ll mx = k, my = l;
            if( p[k][l] < p[i][j+1] ) mx = i, my = j+1;

            if( n_cnt < dp[i][j+1][k][l].first || (n_cnt == dp[i][j+1][k][l].first && n_money > dp[i][j+1][k][l].second) ) {
                dp[i][j+1][mx][my] = P(n_cnt, n_money);
            }
        }
    }
    ll ans = 1e16;
    rep(i,n) rep(j,n) ans = min(ans, dp[n-1][n-1][i][j].first);
    cout << ans << endl;
    
    return 0;
}