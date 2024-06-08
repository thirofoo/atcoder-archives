/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54366385
 * Submitted at: 2024-06-08 22:05:19
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_e
 * Result: AC
 * Execution Time: 53 ms
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
    vector<ll> a(n);
    scc_graph g(n);
    rep(i,n) {
        cin >> a[i]; a[i]--;
        if(i == a[i]) continue;
        g.add_edge(i, a[i]);
    }
    
    vector scc = g.scc();
    vector<ll> group(n);
    ll ans = n;
    rep(i,scc.size()) {
        ans += scc[i].size() * (scc[i].size()-1);
        for(auto v : scc[i]) group[v] = i;
    }

    vector<vector<ll>> Graph(scc.size());
    rep(i,n) {
        if(group[i] == group[a[i]]) continue;
        if(i == a[i]) continue;
        Graph[group[i]].emplace_back(group[a[i]]);
    }
    // DAG なので子のノード数を memo 化再起で求める
    vector<ll> memo(scc.size(), -1);
    auto dfs = [&](auto self, ll v) -> ll {
        if(memo[v] != -1) return memo[v];
        ll res = scc[v].size();
        for(auto nv : Graph[v]) {
            res += self(self, nv);
        }
        return memo[v] = res;
    };
    // cerr << ans << endl;
    rep(i,scc.size()) {
        if(memo[i] == -1) {
            memo[i] = dfs(dfs, i);
        }
        // cerr << memo[i] << " ";
        ans += memo[i] - scc[i].size();
    }
    cout << ans << endl;
    
    return 0;
}