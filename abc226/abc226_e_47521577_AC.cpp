/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/47521577
 * Submitted at: 2023-11-12 13:55:06
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_e
 * Result: AC
 * Execution Time: 93 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    dsu uf(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
        uf.merge(u,v);
    }
    vector g = uf.groups();
    mint ans = 1;
    for(auto v:g) {
        ll num = 0;
        for(auto ele:v) num += Graph[ele].size();
        if( num/2 == v.size() ) ans *= 2;
        else return cout << 0 << endl, 0;
    }
    cout << ans.val() << endl;
    
    return 0;
}