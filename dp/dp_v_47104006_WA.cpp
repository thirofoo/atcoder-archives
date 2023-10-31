/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/47104006
 * Submitted at: 2023-10-31 14:30:28
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_v
 * Result: WA
 * Execution Time: 307 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    modint::set_mod(m);
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        Graph[u].emplace_back(v);
        Graph[v].emplace_back(u);
    }
    // 1. 普通の木dp
    vector<modint> dp1(n,1);
    auto f1 = [&](auto self, ll now, ll pre) -> void {
        for(auto to:Graph[now]) {
            if( to == pre ) continue;
            self(self, to, now);
            dp1[now] *= dp1[to] + 1;
        }
        return;
    };
    f1(f1, 0, -1);
    rep(i,n) cerr << dp1[i].val() << " ";
    cerr << endl;

    // 2. 逆伝搬考慮 (全方位木dp)
    vector<modint> dp2(n, 1);
    vector<vector<modint>> r1(n), r2(n);
    auto f2 = [&](auto self, ll now, ll pre, modint part) -> void {
        // 累積積作成も同時並行
        vector<modint> rui1(Graph[now].size()+1, 1), rui2(Graph[now].size()+1, 1);
        for(int i=0; i<Graph[now].size(); i++) {
            ll to = Graph[now][i];
            rui1[i+1] = rui1[i] * ((to == pre ? part : dp1[to]) + 1);
        }
        r1[now] = rui1;
        for(int i=Graph[now].size()-1; i>=0; i--) {
            ll to = Graph[now][i];
            rui2[i] = rui2[i+1] * ((to == pre ? part : dp1[to]) + 1);
        }
        r2[now] = rui2;

        for(int i=0; i<Graph[now].size(); i++) {
            ll to = Graph[now][i];
            dp2[now] *= ((to == pre ? part : dp1[to]) + 1);
        }
        for(int i=0; i<Graph[now].size(); i++) {
            ll to = Graph[now][i];
            if( to == pre ) continue;
            self(self, to, now, part*rui1[i]*rui2[i+1]);
        }
        return;
    };
    f2(f2, 0, -1, 1);
    rep(i,n) cout << dp2[i].val() << '\n';
    
    return 0;
}