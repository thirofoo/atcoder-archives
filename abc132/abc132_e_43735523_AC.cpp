/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc132/submissions/43735523
 * Submitted at: 2023-07-19 08:21:03
 * Problem URL: https://atcoder.jp/contests/abc132/tasks/abc132_e
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
    }

    ll s,t; cin >> s >> t;
    s--; t--;
    queue<P> todo;
    todo.push(P(0,s));
    vector<vector<ll>> visited(n,vector<ll>(3,1e16));
    while(!todo.empty()){
        auto [time, now] = todo.front(); todo.pop();
        if( visited[now][time%3] <= time ) continue;
        visited[now][time%3] = time;
        time++;
        for(auto next: Graph[now]){
            if( time%3 == 0 && visited[next][time%3] <= time ) continue;
            todo.push( P(time, next) );
        }
    }
    cout << ( visited[t][0] == 1e16 ? -1 : visited[t][0]/3 ) << endl;
    
    return 0;
}