/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46821695
 * Submitted at: 2023-10-21 22:08:26
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_e
 * Result: AC
 * Execution Time: 454 ms
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
    
    ll n, a, b, c; cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n,vector<ll>(n));
    rep(i,n) rep(j,n) cin >> d[i][j];
    priority_queue<T,vector<T>,greater<T>> todo;
    todo.push(T(0,0,0));
    vector<vector<ll>> time(2,vector<ll>(n,1e16));
    while( !todo.empty() ) {
        auto [t, to, s] = todo.top(); todo.pop();
        if( time[s][to] <= t ) continue;
        time[s][to] = t;
        rep(i,n) {
            if( i == to ) continue;
            if( s == 0 && t+d[to][i]*a < time[0][i] ) todo.push(T(t+d[to][i]*a,i,0));
            if( t+d[to][i]*b+c < time[1][i] ) todo.push(T(t+d[to][i]*b+c,i,1));
        }
    }
    cout << min(time[0][n-1], time[1][n-1]) << endl;
    
    return 0;
}