/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc086/submissions/54917913
 * Submitted at: 2024-06-25 14:17:00
 * Problem URL: https://atcoder.jp/contests/arc086/tasks/arc086_c
 * Result: AC
 * Execution Time: 377 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n; cin >> n;
    vector<vector<ll>> Graph(n+1);
    rep(i, n) {
        ll p; cin >> p;
        Graph[p].emplace_back(i+1);
    }

    vector<ll> depth(n+1, 0);
    auto dfs = [&](auto self, ll now, ll par, ll d) -> vector<deque<mint>> {
        // res[i][j] : nowを根とする部分木の深さ j でビー玉が i 個ある場合の数
        vector<deque<mint>> res(3, deque<mint>{}), tmp;
        for(auto &&next: Graph[now]) {
            if(next == par) continue;
            tmp = self(self, next, now, d+1);
            // マージテク (今回は高々頂点数と同じ回数しかマージしないため O(N))
            if(tmp[0].size() > res[0].size()) swap(tmp, res);
            rep(i, tmp[0].size()) {
                mint v1 = res[0][i], v2 = res[1][i], v3 = res[2][i];
                res[0][i] = v1*tmp[0][i];
                res[1][i] = v1*tmp[1][i] + v2*tmp[0][i];
                res[2][i] = (v1+v2+v3)*tmp[2][i] + (v2+v3)*tmp[1][i] + v3*tmp[0][i];
            }
        }
        rep(i, res[2].size()) {
            // ⇓ を入れないとせっかくマージテクしても O(N^2) に元通り
            if(res[2][i] == 0) break;
            res[0][i] += res[2][i];
            res[2][i] = 0;
        }
        res[0].push_front(1);
        res[1].push_front(1);
        res[2].push_front(0);
        depth[now] = d;
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