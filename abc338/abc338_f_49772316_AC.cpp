/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49772316
 * Submitted at: 2024-01-29 00:03:30
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_f
 * Result: AC
 * Execution Time: 656 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<vector<ll>> dis(n,vector<ll>(n,1e16));
    rep(i,n) dis[i][i] = 0;
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        dis[u][v] = w;
    }
    rep(k,n) rep(i,n) rep(j,n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    vector<vector<ll>> dp((1LL << n),vector<ll>(n,1e16));
    rep(i,n) dp[0][i] = 0;
    rep(i,(1LL << n)) {
        rep(j,n) {
            rep(k,n) {
                ll next = i | (1LL << k);
                if( i == next ) continue;
                dp[next][k] = min(dp[next][k], dp[i][j]+dis[j][k]);
            }
        }
    }
    ll ans = 1e16;
    rep(i,n) ans = min(ans, dp[(1LL << n)-1][i]);
    cout << (ans >= 1e15 ? "No" : to_string(ans)) << endl;
    
    return 0;
}