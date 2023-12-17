/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc244/submissions/48612207
 * Submitted at: 2023-12-17 17:04:22
 * Problem URL: https://atcoder.jp/contests/abc244/tasks/abc244_f
 * Result: AC
 * Execution Time: 392 ms
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
    
    ll n, m; cin >> n >> m;
    vector Graph(n,vector<ll>{});
    rep(i,m) {
        ll u, v; cin >> u >> v; u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    // bitDP っぽく BFS (状態が高々 2^N * N 個)
    vector vis(1LL << n,vector<ll>(n,1e16));
    vis[0][0] = 0;
    queue<T> todo; // T(パスの長さ, 最後に訪問した頂点, 状態)
    rep(i,n) todo.push(T(1,i,1LL << i));
    while( !todo.empty() ) {
        auto [dis, now, situ] = todo.front(); todo.pop();
        if( vis[situ][now] != 1e16 ) continue;
        vis[situ][now] = dis;
        for(auto to:Graph[now]) {
            ll next_situ = situ ^ (1LL << to);
            if( vis[next_situ][to] != 1e16 ) continue;
            todo.push(T(dis+1,to,next_situ));
        }
    }
    ll ans = 0;
    rep(i,1LL << n) {
        ll cand = 1e16;
        rep(j,n) cand = min(cand,vis[i][j]);
        ans += cand;
    }
    cout << ans << endl;
    
    return 0;
}