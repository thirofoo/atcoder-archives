/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc132/submissions/43735527
 * Submitted at: 2023-07-19 08:21:28
 * Problem URL: https://atcoder.jp/contests/abc132/tasks/abc132_e
 * Result: TLE
 * Execution Time: 2295 ms
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
    vector<ll> visited(n,1e16);
    while(!todo.empty()){
        auto [time, now] = todo.front(); todo.pop();
        if( time%3 == 0 && visited[now] <= time ) continue;
        if( time%3 == 0 ) visited[now] = time;
        time++;
        for(auto next: Graph[now]){
            if( time%3 == 0 && visited[next] <= time ) continue;
            todo.push( P(time, next) );
        }
    }
    cout << ( visited[t] == 1e16 ? -1 : visited[t]/3 ) << endl;
    
    return 0;
}