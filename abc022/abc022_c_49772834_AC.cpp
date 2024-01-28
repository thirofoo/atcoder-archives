/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc022/submissions/49772834
 * Submitted at: 2024-01-29 00:35:29
 * Problem URL: https://atcoder.jp/contests/abc022/tasks/abc022_c
 * Result: AC
 * Execution Time: 36 ms
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
    vector<vector<ll>> dis(n,vector<ll>(n,1e16));
    rep(i,n) dis[i][i] = 0;
    vector<ll> next1;
    rep(i,m) {
        ll u, v, l; cin >> u >> v >> l; u--; v--;
        dis[u][v] = l;
        dis[v][u] = l;
        if( u == 0 ) next1.emplace_back(v);
    }
    rep(k,n) rep(i,n) rep(j,n) {
        if( k == 0 || i == 0 || j == 0 ) continue;
        dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    }
    ll ans = 1e16;
    rep(i,next1.size()) for(ll j=i+1; j<next1.size(); j++) ans = min(ans, dis[next1[i]][next1[j]]+dis[0][next1[i]]+dis[0][next1[j]]);
    cout << (ans >= 1e16 ? -1 : ans) << endl;
    
    return 0;
}