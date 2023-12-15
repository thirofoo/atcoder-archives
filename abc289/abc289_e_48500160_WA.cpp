/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/48500160
 * Submitted at: 2023-12-15 10:05:16
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_e
 * Result: WA
 * Execution Time: 1132 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while( t-- ) {
        ll n, m; cin >> n >> m;
        vector<ll> c(n);
        vector Graph(n,vector<ll>{});
        vector vis(n,vector(n,vector(2,vector<ll>(2,1e16))));
        rep(i,n) cin >> c[i];
        rep(i,m) {
            ll u, v; cin >> u >> v;
            u--, v--;
            Graph[u].emplace_back(v);
            Graph[v].emplace_back(u);
        }
        queue<T> todo;
        todo.push(T(1, 0,n-1,c[0],c[n-1]));
        while( !todo.empty() ) {
            auto [dis, v1, v2, c1, c2] = todo.front(); todo.pop();
            if( vis[v1][v2][c1][c2] <= dis ) continue;
            vis[v1][v2][c1][c2] = dis;
            for(auto to1:Graph[v1]) {
                for(auto to2:Graph[v2]) {
                    if( vis[to1][to2][c[to1]][c[to2]] <= dis+1 ) continue;
                    todo.push(T(dis+1, to1,to2,c[to1],c[to2]));
                }
            }
        }
        ll ans = min(vis[n-1][0][1][0],vis[n-1][0][0][1]);
        cout << ( ans == 1e16 ? -1 : ans ) << '\n';
    }
    
    return 0;
}