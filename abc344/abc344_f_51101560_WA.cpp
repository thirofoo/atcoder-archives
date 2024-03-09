/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc344/submissions/51101560
 * Submitted at: 2024-03-10 00:27:30
 * Problem URL: https://atcoder.jp/contests/abc344/tasks/abc344_f
 * Result: WA
 * Execution Time: 4449 ms
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

    // 任意 -> 任意 の最短距離
    queue<T> que;
    vector dist(n,vector(n,vector(n,vector<ll>(n,1e16))));
    rep(i,n) rep(j,n) {
        que.push(T(i,j,0));
        while( !que.empty() ) {
            auto [x, y, cost] = que.front(); que.pop();
            if( dist[i][j][x][y] <= cost ) continue;
            dist[i][j][x][y] = cost;
            if( x != n-1 && dist[i][j][x+1][y] > cost+d[x][y] ) que.push(T(x+1,y,cost+d[x][y]));
            if( y != n-1 && dist[i][j][x][y+1] > cost+r[x][y] ) que.push(T(x,y+1,cost+r[x][y]));
        }
    }

    vector<vector<P>> dp(n,vector<P>(n,P(1e16,-1e8)));
    // dp[i][j] : (i,j) 以外で補給しない場合の (i,j) -> (n-1,n-1) の P(最小回数, 残金)
    dp[0][0] = P(0,0);
    rep(i,n) rep(j,n) {
        auto [pre_time, pre_rest] = dp[i][j];
        // 配るDP
        // 同じ回数 ⇒ 残金が大きい方を選ぶ
        // 違う回数 ⇒ 残金 + p[i][j]*time - cost が小さい方を選ぶ
        reps(k,i,n) reps(l,j,n) {
            if( k == i && l == j ) continue;
            // (i,j) -> (k,l) に行く時の遷移
            ll time1 = (dist[i][j][k][l]-1) / p[i][j] + 1 + pre_time + k-i + l-j;
            ll rest1 = p[i][j]*((dist[i][j][k][l]-1) / p[i][j] + 1) + pre_rest - dist[i][j][k][l];
            auto [time2, rest2] = dp[k][l];

            if( time1 == time2 ) dp[k][l].second = max(rest1, rest2);
            else if( time1 < time2 ) {
                ll tmp1 = rest1 + max(0ll, time2-time1)*p[k][l];
                ll tmp2 = rest2 + max(0ll, time1-time2)*p[k][l];
                if( tmp1 >= tmp2 ) dp[k][l] = P(time1, rest1);
            }
        }
    }
    cout << dp[n-1][n-1].first << endl;
    
    return 0;
}