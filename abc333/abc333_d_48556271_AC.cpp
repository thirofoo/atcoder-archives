/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc333/submissions/48556271
 * Submitted at: 2023-12-16 21:19:51
 * Problem URL: https://atcoder.jp/contests/abc333/tasks/abc333_d
 * Result: AC
 * Execution Time: 185 ms
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
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    queue<ll> todo;
    vector<ll> cand;
    vector<bool> vis(n,false);
    for(auto to:Graph[0]) {
        todo.push(to);
        ll size = 0;
        while( !todo.empty() ) {
            ll now = todo.front(); todo.pop();
            if( vis[now] ) continue;
            vis[now] = true;
            size++;
            for(auto next:Graph[now]) {
                if( vis[next] || next == 0 ) continue;
                todo.push(next);
            }
        }
        cand.emplace_back(size);
    }
    sort(cand.begin(), cand.end());
    ll ans = 0;
    rep(i,cand.size()-1) ans += cand[i];
    cout << ans+1 << endl;
    
    return 0;
}