/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc207/submissions/50113179
 * Submitted at: 2024-02-09 16:35:26
 * Problem URL: https://atcoder.jp/contests/abc207/tasks/abc207_f
 * Result: AC
 * Execution Time: 97 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC 
    // 二乗の木dp
    // 部分木を merge していくような木dp の場合
    // merge する時の for文 O(N^2) * mergeの回数 (辺の本数) O(N) ⇒ O(N^3) に見えるが、
    // merge時の dp サイズを部分木のサイズに抑えてあげるだけで本質的に計算量改善され O(N^2) に落ちる。天才すぎ。

    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll u, v; cin >> u >> v; u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    // dp[i][j] : i 個の頂点警備, (j == 0 ? 現頂点に不在 & 未警備 : (j == 1 ? 現頂点に不在 & 警備済 : 現頂点に駐在))
    auto f = [&](auto self, ll now, ll pre) -> vector<vector<mint>> {
        vector<vector<mint>> dp1(2,vector<mint>(3,0)), dp2, ndp;
        dp1[0][0] = dp1[1][2] = 1;
        for(auto &&to:Graph[now]) {
            if( to == pre ) continue;
            dp2 = self(self,to,now);
            ll size = dp1.size()+dp2.size()-1;
            ndp.assign(size,vector<mint>{0,0,0});
            rep(i,dp1.size()) rep(j,dp2.size()) {
                ndp[i+j][0] += dp1[i][0] * (dp2[j][0] + dp2[j][1]);

                // 頂点 now が to によって警備されるケース
                if( i+j+1 < size ) ndp[i+j+1][1] += dp1[i][0] * dp2[j][2];
                ndp[i+j][1] += dp1[i][1] * (dp2[j][0] + dp2[j][1] + dp2[j][2]);

                // 頂点 to が now によって警備されるケース
                if( i+j+1 < size ) ndp[i+j+1][2] += dp1[i][2] * dp2[j][0];
                ndp[i+j][2] += dp1[i][2] * (dp2[j][1] + dp2[j][2]);
            }
            swap(dp1,ndp);
            // cerr << "Now: " << now << endl;
            // rep(i,dp1.size()) {
            //     rep(j,3) cerr << dp1[i][j].val() << " ";
            //     cerr << endl;
            // }
            // cerr << endl;
        }
        return dp1;
    };
    vector ans = f(f,0,-1);
    rep(i,n+1) cout << (ans[i][0]+ans[i][1]+ans[i][2]).val() << endl;
    
    return 0;
}