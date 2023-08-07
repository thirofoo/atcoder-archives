/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/44352793
 * Submitted at: 2023-08-07 11:57:42
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_f
 * Result: AC
 * Execution Time: 736 ms
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
    
    ll n,m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<P> ans1, ans2;
    vector<ll> visited(n,-1);
    visited[0] = -2;
    queue<T> todo;
    rep(i,Graph[0].size()) todo.push(T(Graph[0][i],i,0));
    while( !todo.empty() ) {
        auto [now, g, pre] = todo.front(); todo.pop();
        if( visited[now] != -1 ) continue;
        visited[now] = g;
        ans1.push_back( P(now+1, pre+1) );
        for(auto to:Graph[now]) {
            if( visited[to] != -1 ) continue;
            todo.push(T(to,g,now));
        }
    }

    bool f = false;
    visited.assign(n, 0);
    auto dfs = [&](auto self, ll now, ll cnt) -> void {
        visited[now] = 1;
        for(auto to:Graph[now]) {
            if( visited[to] ) continue;
            ans2.push_back( P(now+1, to+1) );
            self(self, to, cnt+1);
        }
        return;
    };
    dfs(dfs, 0, 1);
    
    rep(i, ans2.size()) cout << ans2[i].first << " " << ans2[i].second << endl;
    rep(i, ans1.size()) cout << ans1[i].first << " " << ans1[i].second << endl;
    
    return 0;
}