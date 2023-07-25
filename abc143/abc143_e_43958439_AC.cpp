/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc143/submissions/43958439
 * Submitted at: 2023-07-26 02:48:39
 * Problem URL: https://atcoder.jp/contests/abc143/tasks/abc143_e
 * Result: AC
 * Execution Time: 195 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC ワーシャルフロイド2回 (天才)
    // 1. 全頂点対最短経路を求める
    // 2. ↑を元に補給するかしないかのコストを策定
    // 3. ↑のコストでもう一度ワーシャルフロイド

    ll n,m,l; cin >> n >> m >> l;
    vector dis(n,vector<ll>(n,1e16)), ans(n,vector<ll>(n,1e16));
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    rep(i,n) dis[i][i] = 0;
    rep(i,n)rep(j,n)rep(k,n) dis[j][k] = min( dis[j][k], dis[j][i]+dis[i][k] );
    rep(i,n)rep(j,n) {
        if( dis[i][j] == 0 ) ans[i][j] = 0;
        else if( dis[i][j] <= l ) ans[i][j] = 1;
    }
    rep(i,n)rep(j,n)rep(k,n) ans[j][k] = min( ans[j][k], ans[j][i]+ans[i][k] );

    ll q; cin >> q;
    while(q--) {
        ll s,t; cin >> s >> t;
        s--; t--;
        cout << ( ans[s][t] == 1e16 ? -1 : ans[s][t]-1 ) << endl;
    }
    
    return 0;
}