/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/46219050
 * Submitted at: 2023-10-05 01:38:21
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
 * Result: AC
 * Execution Time: 165 ms
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
    vector<P> e;
    rep(i,m) {
        ll s, t; cin >> s >> t;
        s--; t--;
        Graph[s].emplace_back(t);
        e.emplace_back(P(s,t));
    }
    sort(e.begin(), e.end());
    queue<P> todo;
    todo.push(P(0,-1));
    vector visited(n,-1), v2(n,-1);
    vector pre(n,-1);
    while( !todo.empty() ) {
        auto [now, p] = todo.front(); todo.pop();
        if( visited[now] != -1 ) continue;
        visited[now] = ( p == -1 ? 0 : visited[p] + 1);
        pre[now] = p;
        for(auto to:Graph[now]) {
            if( visited[to] != -1 ) continue;
            todo.push(P(to, now));
        }
    }
    // 最短経路上にある辺を削除した時だけ愚直
    set<ll> side;
    ll p = n-1;
    if( pre[p] == -1 ) {
        rep(i,m) cout << -1 << endl;
        return 0;
    }
    while( pre[p] != -1 ) {
        auto itr = lower_bound(e.begin(), e.end(), P(pre[p],p));
        side.insert( itr-e.begin() );
        p = pre[p];
    }

    rep(i,m) {
        if( !side.count(i) ) {
            cout << visited[n-1] << endl;
            continue;
        }
        todo.push(P(0,-1));
        v2.assign(n,-1);
        while( !todo.empty() ) {
            auto [now, p] = todo.front(); todo.pop();
            if( v2[now] != -1 ) continue;
            v2[now] = ( p == -1 ? 0 : v2[p] + 1 );
            for(auto to:Graph[now]) {
                if( v2[to] != -1) continue;
                ll idx = lower_bound(e.begin(), e.end(), P(now, to)) - e.begin();
                if( idx == i ) continue;
                todo.push(P(to, now));
            }
        }
        cout << (v2[n-1] == -1 ? -1 : v2[n-1]) << endl;
    }
    
    return 0;
}