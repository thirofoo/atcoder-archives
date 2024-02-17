/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50395113
 * Submitted at: 2024-02-17 23:48:21
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_f
 * Result: RE
 * Execution Time: 128 ms
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
    vector<P> edge;
    vector<vector<ll>> Graph(n);
    rep(i,m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        if( u > v ) swap(u, v);
        edge.emplace_back(P(u, v));
    }
    vector<ll> w(n), a(n);
    rep(i,n) cin >> w[i];
    rep(i,n) cin >> a[i];
    // a が大 ⇒ 小に向けて有向辺作成
    rep(i,m) {
        ll u, v; tie(u, v) = edge[i];
        if(w[u] > w[v]) Graph[u].emplace_back(v);
        if(w[u] < w[v]) Graph[v].emplace_back(u);
    }
    rep(i,n) {
        sort(Graph[i].begin(), Graph[i].end());
        Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end());
    }

    // トポロジカルソート
    vector<ll> sorted;
    vector<ll> in(n, 0);
    rep(i,n) for(auto &e : Graph[i]) in[e]++;
    queue<ll> que;
    rep(i,n) if(in[i] == 0) que.push(i);
    while(!que.empty()) {
        ll v = que.front(); que.pop();
        sorted.emplace_back(v);
        for(auto &e : Graph[v]) {
            in[e]--;
            if(in[e] == 0) que.push(e);
        }
    }
    // トポロジカルソートが遅い順に DP
    reverse(sorted.begin(), sorted.end());
    vector<ll> ans(n, 1);

    rep(i,n) {
        ll ni = sorted[i];
        // 自身か行ける頂点でナップサック DP
        vector<vector<ll>> dp(Graph[ni].size()+1, vector<ll>(w[ni], 0));
        rep(j,Graph[ni].size()) {
            ll to = Graph[ni][j];
            // cerr << "to: " << to << " " << ans[to] << endl;
            rep(k,w[ni]+1) {
                dp[j+1][k] = max(dp[j+1][k], dp[j][k]);
                ll nk = k+w[to];
                if( nk < w[ni] ) dp[j+1][nk] = max(dp[j+1][nk], dp[j][k]+ans[to]);
            }
        }
        // cerr << "ni: " << ni << endl;
        // rep(j,Graph[ni].size()+1) {
        //     rep(k,w[ni]) cerr << dp[j][k] << ' ';
        //     cerr << endl;
        // }
        ll maxi = 0;
        rep(j,w[ni]) maxi = max(maxi, dp[Graph[ni].size()][j]);
        ans[ni] += maxi;
        // rep(i,n) cerr << ans[i] << ' ';
        // cerr << endl << endl;
    }
    ll answer = 0;
    rep(i,n) answer += ans[i] * a[i];
    cout << answer << endl;
    
    return 0;
}