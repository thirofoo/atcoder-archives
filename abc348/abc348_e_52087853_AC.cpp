/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc348/submissions/52087853
 * Submitted at: 2024-04-06 21:34:17
 * Problem URL: https://atcoder.jp/contests/abc348/tasks/abc348_e
 * Result: AC
 * Execution Time: 57 ms
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
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    vector<ll> c(n);
    rep(i,n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }
    rep(i,n) cin >> c[i];
    // 1 を根として求める ⇒ 差分更新
    vector<ll> dist(n, 1e16), cost = c;
    auto dfs = [&](auto dfs, ll now, ll par, ll depth) -> void {
        dist[now] = depth;
        for(auto next: Graph[now]) {
            if( next == par ) continue;
            dfs(dfs, next, now, depth+1);
        }
        // 帰りがけで累積和
        if( par != -1 ) cost[par] += cost[now];
    };
    dfs(dfs, 0, -1, 0);

    ll ans = 0, total = 0;
    rep(i,n) {
        ans += c[i] * dist[i];
        total += c[i];
    }
    queue<T> todo;
    todo.push(T(ans, 0, -1));
    while( !todo.empty() ) {
        auto [cand, now, pre] = todo.front(); todo.pop();
        ans = min(ans, cand);
        for(auto next: Graph[now]) {
            if( next == pre ) continue;
            todo.push(T(cand-cost[next]+total-cost[next], next, now));
        }
    }
    cout << ans << '\n';
    
    return 0;
}