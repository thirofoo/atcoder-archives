/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32828410
 * Submitted at: 2022-06-29 14:20:48
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_f
 * Result: WA
 * Execution Time: 570 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n+1);
    rep(i,m){
        int u,v; cin >> u >> v;
        if(u != 0)Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    int d_tle = INT_MAX;
    vector<int> dfrom1(n+1,INT_MAX),dfromn(n+1,INT_MAX);
    vector<bool> visited(n+1,false);
    queue<P> todo;
    todo.push(P(1,0));
    while(!todo.empty()){
        auto [now,d] = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        dfrom1[now] = d;
        for(auto k:Graph[now]){
            if(k == 0)d_tle = min(d_tle,dfrom1[now]+1);
            else todo.push(P(k,dfrom1[now]+1));
        }
    }
    visited.assign(n+1,false);
    todo.push(P(n,0));
    while(!todo.empty()){
        auto [now,d] = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        dfromn[now] = d;
        for(auto k:Graph[now]){
            if(k != 0)todo.push(P(k,dfromn[now]+1));
        }
    }
    rep(i,n){
        int ans = min(dfrom1[n],(d_tle == INT_MAX || dfromn[i+1] == INT_MAX ? INT_MAX : d_tle+dfromn[i+1]));
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    
    return 0;
}