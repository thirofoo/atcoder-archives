/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54867425
 * Submitted at: 2024-06-23 13:51:57
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_g
 * Result: AC
 * Execution Time: 395 ms
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
    
    // 解説 AC : マージテク
    // DFS の帰りがけでマージすると O(N^2) になりそうだが、マージテクで間に合う
    // LCA が各頂点である時の寄与を見る時に、各子の部分木における深さ総和が必要
    // ⇒ これは元の木の各頂点の深さを depth として ∑_{v in 部分木} (depth[v]-depth[p]) = ∑ depth[v] - num * depth[p]
    // ⇒ 現在の頂点を根とした木における P(個数, 深さ総和) を持つマージテクで解ける

    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    auto dfs = [&](auto self, ll now, ll prev, ll depth) -> map<ll, P> {
        map<ll, P> res; // res[色] = P(個数, 深さの総和)
        for(auto to : Graph[now]) {
            if(to == prev) continue;
            auto sub = self(self, to, now, depth+1);
            if(res.size() < sub.size()) swap(res, sub);
            for(auto [color, p] : sub) {
                auto [cnt1, d_sum1] = p;
                auto [cnt2, d_sum2] = res[color];
                res[color] = {cnt1 + cnt2, d_sum1 + d_sum2};
                ans += (d_sum2 - cnt2 * depth) * cnt1 + (d_sum1 - cnt1 * depth) * cnt2;
            }
        }
        // 自身を追加
        auto [cnt, d_sum] = res[a[now]];
        ans += d_sum - cnt * depth;
        res[a[now]] = {cnt + 1, d_sum + depth};
        // cerr << "now: " << now << ", ans: " << ans << " , d_sum - cnt * depth: " << d_sum - cnt * depth << '\n';
        // for(auto [color, p] : res) cerr << color << ' ' << p.first << ' ' << p.second << '\n';
        return res;
    };
    map<ll, P> mp = dfs(dfs, 0, -1, 0);
    cout << ans << '\n';
    
    return 0;
}