/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50161267
 * Submitted at: 2024-02-10 21:29:32
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_d
 * Result: AC
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    
    ll n; cin >> n;
    vector<vector<P>> Graph(n);
    rep(i,n-1) {
        ll a, b, x; cin >> a >> b >> x; x--;
        Graph[i].emplace_back(P(x,b));
        Graph[i].emplace_back(P(i+1,a));
    }
    // dijkstra
    vector<ll> dist(n, 1e18);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[0] = 0;
    pq.push(P(0,0));
    while( !pq.empty() ) {
        auto [d, v] = pq.top(); pq.pop();
        if( dist[v] < d ) continue;
        for(auto [nv, w] : Graph[v]) {
            if( dist[nv] > dist[v]+w ) {
                dist[nv] = dist[v]+w;
                pq.push(P(dist[nv],nv));
            }
        }
    }
    cout << dist[n-1] << endl;
    
    return 0;
}