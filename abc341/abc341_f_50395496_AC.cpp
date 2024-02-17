/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50395496
 * Submitted at: 2024-02-17 23:58:40
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_f
 * Result: AC
 * Execution Time: 147 ms
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
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    rep(i,m) {
        ll u, v; cin >> u >> v; u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    vector<ll> w(n), a(n), p(n), ans(n,1);
    rep(i,n) cin >> w[i];
    rep(i,n) cin >> a[i];
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](ll i, ll j) { return w[i] < w[j]; });

    rep(i,n) {
        ll ni = p[i];
        // 自身が行ける頂点でナップサック DP
        vector<vector<ll>> dp(Graph[ni].size()+1, vector<ll>(w[ni], 0));
        rep(j,Graph[ni].size()) {
            ll to = Graph[ni][j];
            rep(k,w[ni]) {
                dp[j+1][k] = max(dp[j+1][k], dp[j][k]);
                ll nk = k + w[to];
                if( nk < w[ni] ) dp[j+1][nk] = max(dp[j+1][nk], dp[j][k]+ans[to]);
            }
        }
        ll max_v = 0;
        rep(j,w[ni]) max_v = max(max_v, dp.back()[j]);
        ans[ni] += max_v;
    }
    ll answer = 0;
    rep(i,n) answer += ans[i] * a[i];
    cout << answer << endl;
    
    return 0;
}