/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/49812837
 * Submitted at: 2024-01-30 19:56:13
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: TLE
 * Execution Time: 2210 ms
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

#define COLOR_CNT 3
const vector<vector<ll>> c_idx = {{1,2},{0,2},{0,1}};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC (天才過ぎ)
    // 一色固定 → 二部グラフ判定

    ll n, m; cin >> n >> m;
    vector<vector<ll>> Graph(n);
    vector<vector<bool>> next(n,vector<bool>(n,false));
    rep(i,m) {
        ll a, b; cin >> a >> b; a--, b--;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
        next[a][b] = true;
        next[b][a] = true;
    }
    ll ans = 0;
    rep(i,(1LL << n)) {
        // dsu でも 二部グラフ判定が可能 (より直感的)
        vector<ll> fixed;
        bool f = true;
        rep(j,n) if( i & (1LL << j) ) fixed.emplace_back(j);
        ll size = fixed.size();
        rep(j,size) for(ll k=j+1; k<size; k++) f &= !next[fixed[j]][fixed[k]];

        dsu uf(2*n);
        rep(now,n) {
            if( i & (1LL << now) ) continue;
            for(auto to:Graph[now]) {
                if( i & (1LL << to) ) continue;
                uf.merge(now,to+n);
                uf.merge(now+n,to);
            }
        }
        rep(j,n) f &= (!uf.same(j,n+j));
        vector g = uf.groups();
        if( f ) ans += (1LL << ((g.size()-2*size)/2));
    }
    cout << ans << endl;
    
    return 0;
}