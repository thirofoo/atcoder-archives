/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/44399690
 * Submitted at: 2023-08-09 09:42:22
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_c
 * Result: AC
 * Execution Time: 123 ms
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
    
    ll n,x,y; cin >> n >> x >> y;
    x--; y--;
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll u,v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }

    bool f = false;
    vector<ll> ans;
    vector<bool> visited(n,false);
    auto dfs = [&](auto self, ll now) -> void {
        visited[now] = true;
        ans.emplace_back(now);
        if( now == y ) {
            f = true;
            return;
        }
        for(auto to:Graph[now]) {
            if( visited[to] ) continue;
            self(self,to);
            if( f ) return;
        }
        ans.pop_back();
    };
    dfs(dfs,x);
    for(auto ele:ans) cout << ele+1 << " ";
    cout << endl;
    
    return 0;
}