/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50615469
 * Submitted at: 2024-02-24 23:37:39
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_e
 * Result: AC
 * Execution Time: 319 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll, ll>;
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
    vector<vector<T>> Graph(n);
    rep(i,m) {
        ll l, d, k, c, a, b; cin >> l >> d >> k >> c >> a >> b; a--; b--;
        Graph[b].push_back(T(a, l, d, k, c));
    }
    vector<ll> dist(n, 2e18);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(-2e18,n-1));
    // 逆辺で dijkstra
    while( !pq.empty() ) {
        auto [t, v] = pq.top(); pq.pop();
        if( dist[v] <= t ) continue;
        dist[v] = t;
        for(auto &&[nv, l, d, k, c] : Graph[v]) {
            ll nt = ((t+l+c)/d)*d - l;
            if( -l < nt ) continue;
            nt = max(nt, -(l+(k-1)*d));
            if( dist[nv] <= nt ) continue;
            pq.push(P(nt, nv));
        }
    }
    rep(i,n-1) cout << (dist[i] == 2e18 ? "Unreachable" : to_string(-dist[i])) << endl;
    
    return 0;
}