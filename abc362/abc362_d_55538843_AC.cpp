/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55538843
 * Submitted at: 2024-07-13 21:28:33
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_d
 * Result: AC
 * Execution Time: 111 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<pair<ll, ll>>> Graph(n);
    rep(i, m) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        Graph[u].emplace_back(pair{v, b});
        Graph[v].emplace_back(pair{u, b});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq;
    vector<ll> dist(n, INF);
    pq.push(pair{a[0], 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] <= d) continue;
        dist[u] = d;
        for(auto [v, b] : Graph[u]) {
            if(dist[v] > d + b + a[v]) {
                pq.push(pair{d + b + a[v], v});
            }
        }
    }

    for(int i = 1; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}