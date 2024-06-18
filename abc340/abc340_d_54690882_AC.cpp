/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/54690882
 * Submitted at: 2024-06-18 18:38:42
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_d
 * Result: AC
 * Execution Time: 99 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n-1), b(n-1), x(n-1);
    vector<vector<P>> Graph(n);
    rep(i, n-1) {
        cin >> a[i] >> b[i] >> x[i];
        x[i]--;
        Graph[i].emplace_back(P(i+1, a[i]));
        Graph[i].emplace_back(P(x[i], b[i]));
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(n, INF);
    pq.push(P(0, 0));
    dist[0] = 0;
    while(!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;
        for(auto &&[nv, nc]:Graph[v]) {
            if(dist[nv] > d + nc) {
                dist[nv] = d + nc;
                pq.push(P(dist[nv], nv));
            }
        }
    }
    cout << dist[n-1] << endl;

    return 0;
}