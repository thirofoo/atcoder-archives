/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49119747
 * Submitted at: 2024-01-06 22:36:41
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_e
 * Result: AC
 * Execution Time: 128 ms
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> Graph(n);
    dsu uf(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        if( a[u] == a[v] ) uf.merge(u,v);
    }
    vector<P> p;
    rep(i,n) p.push_back(P(a[i],i));
    sort(p.begin(),p.end());

    // 隣接ノードが同じ数の時は双方向で行ける
    // ⇒ いくらでも行ったり来たり出来る為連結成分の個数分だけ最後に足せる
    vector g = uf.groups();
    sort(g.begin(), g.end(), [&](vector<int> &e1, vector<int> &e2) {
        return a[e1[0]] < a[e2[0]];
    });

    vector<ll> dp(n,0);
    dp[0] = 1;
    ll g_idx = 0;
    rep(i,n) {
        auto [d, now] = p[i];
        // 始めは狭義単調増加で調査
        for(auto pre:Graph[now]) {
            if( a[now] > a[pre] && dp[pre] != 0 ) {
                dp[now] = max(dp[now], dp[pre]+1);
            }
        }
        // d が異なる境界で同じ連結成分の dp を更新
        if( i == n-1 || d != p[i+1].first ) {
            while( g_idx < g.size() && a[g[g_idx][0]] <= d ) {
                ll max_ele = 0;
                for(auto ele:g[g_idx]) max_ele = max(max_ele, dp[ele]);
                for(auto ele:g[g_idx]) dp[ele] = max_ele;
                g_idx++;
            }
        }
    }
    cout << dp[n-1] << endl;
    
    return 0;
}
