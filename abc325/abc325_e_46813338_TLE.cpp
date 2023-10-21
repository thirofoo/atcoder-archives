/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc325/submissions/46813338
 * Submitted at: 2023-10-21 21:40:47
 * Problem URL: https://atcoder.jp/contests/abc325/tasks/abc325_e
 * Result: TLE
 * Execution Time: 2209 ms
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
    priority_queue<P> todo;
    todo.push(P(0,0));
    vector<ll> time(n,1e16);
    while( !todo.empty() ) {
        auto [t, to] = todo.top(); todo.pop();
        if( time[to] <= t ) continue;
        time[to] = t;
        rep(i,n) {
            if( i == to ) continue;
            if( t+d[to][i]*a < time[i] ) todo.push(P(t+d[to][i]*a,i));
            if( t+d[to][i]*b+c < time[i] ) todo.push(P(t+d[to][i]*b+c,i));
        }
    }
    cout << time[n-1] << endl;
    
    return 0;
}