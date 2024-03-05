/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50924981
 * Submitted at: 2024-03-05 19:11:01
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_m
 * Result: AC
 * Execution Time: 143 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    // 始点・終点から dijkstra
    vector<vector<P>> Graph(n);
    rep(i,m) {
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        Graph[a].emplace_back(P(b,c));
        Graph[b].emplace_back(P(a,c));
    }
    vector<ll> s_dist(n,1e16), g_dist(n,1e16);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0,0));
    while( !pq.empty() ) {
        auto [d, now] = pq.top(); pq.pop();
        if( s_dist[now] <= d ) continue;
        s_dist[now] = d;
        for(auto [to,c]:Graph[now]) {
            if( s_dist[to] <= d+c ) continue;
            pq.push(P(d+c, to));
        }
    }
    pq.push(P(0,n-1));
    while( !pq.empty() ) {
        auto [d, now] = pq.top(); pq.pop();
        if( g_dist[now] <= d ) continue;
        g_dist[now] = d;
        for(auto [to,c]:Graph[now]) {
            if( g_dist[to] <= d+c ) continue;
            pq.push(P(d+c, to));
        }
    }
    rep(i,n) cout << s_dist[i] + g_dist[i] << endl;
    
    return 0;
}