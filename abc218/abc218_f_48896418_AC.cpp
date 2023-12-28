/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/48896418
 * Submitted at: 2023-12-28 16:15:32
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
 * Result: AC
 * Execution Time: 184 ms
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
    vector<vector<ll>> Graph(n);
    map<P,ll> mp;
    rep(i, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        mp[P(a,b)] = i;
    }
    vector<ll> dist(n, 1e16), pre(n, -1);
    queue<T> todo;
    todo.push(T(0, 0, -1));
    while( !todo.empty() ) {
        auto [v, d, p] = todo.front(); todo.pop();
        if( dist[v] != 1e16 ) continue;
        dist[v] = d;
        pre[v] = p;
        for( ll nv : Graph[v] ) {
            if( dist[nv] != 1e16 ) continue;
            todo.push(T(nv, d+1, v));
        }
    }
    set<ll> edge_idx;
    ll goal = n-1;
    while( pre[goal] != -1 ) {
        edge_idx.insert(mp[P(pre[goal], goal)]);
        goal = pre[goal];
    }
    rep(i,m) {
        if( !edge_idx.count(i) ) cout << (dist[n-1] == 1e16 ? -1 : dist[n-1]) << endl;
        else {
            vector<ll> ndist(n, 1e16);
            queue<P> todo;
            todo.push(P(0, 0));
            while( !todo.empty() ) {
                auto [v, d] = todo.front(); todo.pop();
                if( ndist[v] != 1e16 ) continue;
                ndist[v] = d;
                for( ll nv : Graph[v] ) {
                    if( ndist[nv] != 1e16 || mp[P(v,nv)] == i ) continue;
                    todo.push(P(nv, d+1));
                }
            }
            cout << (ndist[n-1] == 1e16 ? -1 : ndist[n-1]) << endl;
        }
    }
    
    return 0;
}