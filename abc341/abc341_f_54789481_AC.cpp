/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/54789481
 * Submitted at: 2024-06-22 20:52:52
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_f
 * Result: AC
 * Execution Time: 135 ms
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
    vector<vector<ll>> Graph(n);
    vector<P> edge;
    rep(i, m) {
        ll u, v; cin >> u >> v; u--; v--;
        edge.emplace_back(u, v);
    }
    vector<ll> w(n), a(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> a[i];
    rep(i, m) {
        auto [u, v] = edge[i];
        if(w[u] > w[v]) Graph[u].emplace_back(v);
        else if(w[u] < w[v]) Graph[v].emplace_back(u);
    }
    
    ll ans = 0;
    // memo[i] : 頂点 i にいる駒を取り外す時の手数
    vector<ll> memo(n, -1);
    auto dfs = [&](auto self, ll now) -> void {
        if(memo[now] != -1) return;
        vector dp(Graph[now].size()+1, vector<ll>(w[now], -INF));
        dp[0][0] = 0;
        rep(i, Graph[now].size()) {
            ll next = Graph[now][i];
            self(self, next);
            rep(j, w[now]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                if(j+w[next] < w[now]) {
                    dp[i+1][j+w[next]] = max(dp[i+1][j+w[next]], dp[i][j]+memo[next]);
                }
            }
        }
        ll res = 0;
        rep(i, w[now]) res = max(res, dp[Graph[now].size()][i]);
        res++; // 初手の移動分を考慮
        memo[now] = res;
        ans += memo[now] * a[now];

        return;
    };
    rep(i, n) dfs(dfs, i);
    cout << ans << endl;
    
    return 0;
}