/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44796378
 * Submitted at: 2023-08-20 23:55:23
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_f
 * Result: AC
 * Execution Time: 182 ms
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
    
    ll n; cin >> n;
    dsu d(n);
    vector<ll> g(n);
    vector<ll> sz(2 * n - 1, 1);
    iota(g.begin(), g.end(), 0);
    vector<vector<ll>> to(2 * n - 1);
 
    rep(i,n-1) {
        ll p, q; cin >> p >> q;
        p--, q--;
        p = d.leader(p);
        q = d.leader(q);
        d.merge(p, q);
        to[n + i] = {g[p], g[q]};
        g[d.leader(p)] = n + i;
        sz[n + i] = d.size(p);
    }
 
    vector<mint> dp(n * 2 - 1);
        auto dfs = [&](auto self, ll v) -> void {
        for (ll nv : to[v]) {
            dp[nv] = dp[v] + mint(sz[nv]) / sz[v];
            self(self, nv);
        }
        return;
    };
    dfs(dfs, 2 * n - 2);
    rep(i,n) cout << dp[i].val() << " ";
    cout << endl;
    
    return 0;
}