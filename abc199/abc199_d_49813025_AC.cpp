/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/49813025
 * Submitted at: 2024-01-30 20:04:04
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_d
 * Result: AC
 * Execution Time: 1068 ms
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
    dsu uf;
    ll ans = 0;
    vector<ll> fix;
    rep(i,(1LL << n)) {
        // dsu でも 二部グラフ判定が可能 (より直感的)
        fix.assign({});
        rep(j,n) if( i & (1LL << j) ) fix.emplace_back(j);
        bool f = true;
        ll size = fix.size();
        rep(j,size) for(ll k=j+1; k<size; k++) f &= !next[fix[j]][fix[k]];
        if( !f ) continue;

        uf = dsu(2*n);
        rep(now,n) {
            if( i & (1LL << now) ) continue;
            for(auto &&to:Graph[now]) {
                if( i & (1LL << to) ) continue;
                uf.merge(now,to+n);
                uf.merge(now+n,to);
            }
        }
        rep(j,n) f &= (!uf.same(j,n+j));
        if( f ) ans += (1LL << ((uf.groups().size()-2*size)/2));
    }
    cout << ans << endl;
    
    return 0;
}