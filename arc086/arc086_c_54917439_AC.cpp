/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc086/submissions/54917439
 * Submitted at: 2024-06-25 13:54:56
 * Problem URL: https://atcoder.jp/contests/arc086/tasks/arc086_c
 * Result: AC
 * Execution Time: 332 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n+1);
    rep(i, n) {
        ll p; cin >> p;
        Graph[p].emplace_back(i+1);
    }

    // 各頂点を根とする部分木毎に答えの寄与をもとめるのは NG
    // ※ 部分木の部分木は部分木であるため重複の数え上げが発生
    // ⇒ 木dp で親に伝搬させて最後に答えを求める
    vector<ll> depth(n+1, 0);
    auto dfs = [&](auto self, ll now, ll par, ll d) -> vector<deque<mint>> {
        // now の深さ算出
        depth[now] = d;

        // res[i][j] : nowを根とする部分木の深さ j でビー玉が i 個ある場合の数
        vector<deque<mint>> res(3, deque<mint>{});
        for(auto next: Graph[now]) {
            if(next == par) continue;
            vector<deque<mint>> tmp = self(self, next, now, d+1);
            if(tmp[0].size() > res[0].size()) swap(tmp, res);
            rep(i, tmp[0].size()) {
                mint v1 = res[0][i], v2 = res[1][i], v3 = res[2][i];
                res[0][i] = v1*tmp[0][i];
                res[1][i] = v1*tmp[1][i] + v2*tmp[0][i];
                res[2][i] = (v1+v2+v3)*tmp[2][i] + (v2+v3)*tmp[1][i] + v3*tmp[0][i];
            }
        }
        rep(i, res[2].size()) {
            if(res[2][i] == 0) break;
            res[0][i] += res[2][i];
            res[2][i] = 0;
        }
        res[0].push_front(1);
        res[1].push_front(1);
        res[2].push_front(0);
        return res;
    };
    mint ans = 0;
    vector<deque<mint>> res = dfs(dfs, 0, -1, 0);
    vector<ll> d_cnt(n+1, 0);
    rep(i, n+1) d_cnt[depth[i]] += 1;
    rep(i, res[1].size()) ans += res[1][i] * mint(2).pow(n+1-d_cnt[i]);
    cout << ans.val() << endl;
    
    return 0;
}