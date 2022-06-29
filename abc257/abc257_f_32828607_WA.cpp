/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32828607
 * Submitted at: 2022-06-29 14:32:38
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_f
 * Result: WA
 * Execution Time: 561 ms
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
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> Graph(n+1);
    rep(i,m){
        ll u,v; cin >> u >> v;
        if(u != 0)Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    ll d_tle_1 = LLONG_MAX;
    vector<ll> dfrom1(n+1,LLONG_MAX),dfromn(n+1,LLONG_MAX);
    vector<bool> visited(n+1,false);
    queue<P> todo;
    todo.push(P(1,0));
    while(!todo.empty()){
        auto [now,d] = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        dfrom1[now] = d;
        for(auto k:Graph[now]){
            if(k == 0)d_tle_1 = min(d_tle_1,dfrom1[now]+1);
            else todo.push(P(k,dfrom1[now]+1));
        }
    }

    ll d_tle_n = LLONG_MAX;
    visited.assign(n+1,false);
    todo.push(P(n,0));
    while(!todo.empty()){
        auto [now,d] = todo.front(); todo.pop();
        if(visited[now])continue;
        visited[now] = true;
        dfromn[now] = d;
        for(auto k:Graph[now]){
            if(k == 0)d_tle_n = min(d_tle_n,dfromn[now]+1);
            else todo.push(P(k,dfromn[now]+1));
        }
    }
    rep(i,n){
        ll ans = min(dfrom1[n],(d_tle_1 == LLONG_MAX || dfromn[i+1] == LLONG_MAX ? LLONG_MAX : d_tle_1+dfromn[i+1]));
        ans = min(ans,(d_tle_n == LLONG_MAX || dfrom1[i+1] == LLONG_MAX ? LLONG_MAX : d_tle_n+dfrom1[i+1]));
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
    
    return 0;
}