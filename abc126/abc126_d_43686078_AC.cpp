/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc126/submissions/43686078
 * Submitted at: 2023-07-17 13:10:20
 * Problem URL: https://atcoder.jp/contests/abc126/tasks/abc126_d
 * Result: AC
 * Execution Time: 190 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<P>> Graph(n);
    rep(i,n-1){
        ll u,v,w; cin >> u >> v >> w;
        u--; v--;
        Graph[u].push_back(P(v,w));
        Graph[v].push_back(P(u,w));
    }
    vector<ll> visited(n,-1);
    queue<P> todo;
    todo.push(P(0, 0));
    while( !todo.empty() ){
        auto [now, dis] = todo.front(); todo.pop();
        if( visited[now] != -1 ) continue;
        visited[now] = dis;
        for(auto [to,nw]:Graph[now]){
            if( visited[to] != -1 ) continue;
            todo.push( P(to,(dis+nw)%2) );
        }
    }
    rep(i,n) cout << visited[i] << endl;
    
    return 0;
}