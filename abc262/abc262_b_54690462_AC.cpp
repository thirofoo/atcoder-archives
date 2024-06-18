/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc262/submissions/54690462
 * Submitted at: 2024-06-18 18:24:44
 * Problem URL: https://atcoder.jp/contests/abc262/tasks/abc262_b
 * Result: AC
 * Execution Time: 4 ms
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
    vector<vector<bool>> Graph(n, vector<bool>(n, false));
    rep(i, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u][v] = Graph[v][u] = true;
    }
    ll ans = 0;
    rep(i, n) rep(j, n) rep(k, n) {
        if(i == j || j == k || k == i) continue;
        if(Graph[i][j] && Graph[j][k] && Graph[k][i]) ans++;
    }
    cout << ans/6 << endl;
    
    return 0;
}