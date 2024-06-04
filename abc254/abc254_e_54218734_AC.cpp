/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/54218734
 * Submitted at: 2024-06-04 14:00:59
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_e
 * Result: AC
 * Execution Time: 313 ms
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
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    rep(i, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    };
    vector dist_cnt(n, vector<ll>(4, 0));
    vector<ll> dist(n, -1), store;
    queue<P> q;
    rep(i, n) {
        q.push({i, 0});
        while(!q.empty()) {
            auto [v, d] = q.front(); q.pop();
            if(dist[v] != -1) continue;
            dist[v] = d;
            dist_cnt[i][d] += v+1;
            store.push_back(v);
            if(d >= 3) continue;
            for(ll nv : Graph[v]) {
                if(dist[nv] != -1) continue;
                q.push({nv, d+1});
            }
        }
        for(ll v : store) dist[v] = -1;
        store.clear();
    }

    ll Q; cin >> Q;
    while(Q--) {
        ll x, k; cin >> x >> k; x--;
        ll ans = 0;
        rep(i, k+1) ans += dist_cnt[x][i];
        cout << ans << endl;
    }
    
    return 0;
}