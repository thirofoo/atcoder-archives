/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc143/submissions/43958207
 * Submitted at: 2023-07-26 02:25:11
 * Problem URL: https://atcoder.jp/contests/abc143/tasks/abc143_e
 * Result: WA
 * Execution Time: 243 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,l; cin >> n >> m >> l;
    vector dp(n,vector<P>(n,P( -1, 1e16 )));
    vector<vector<ll>> cost(n,vector<ll>(n,-1));
    rep(i,n) dp[i][i] = P(l,0);
    dsu uf(n);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = c;
        cost[b][a] = c;
        if( c <= l ) {
            dp[a][b] = P(l-c,0);
            dp[b][a] = P(l-c,0);
            uf.merge(a,b);
        }
    }

    // 多くとも N-1回 補給で間に合うはず
    // 補給回数は少ないに越したことは無さそう → 補給回数と現時点の燃料を持つ ワーシャルフロイド
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if( cost[k][j] == -1 ) continue;
                auto [rest, time] = dp[i][k];
                ll next_time = time + ( rest < cost[k][j] ? 1 : 0 );
                ll next_rest = ( rest < cost[k][j] ? l : rest ) - cost[k][j];

                if( next_time < dp[i][j].second || ( next_time == dp[i][j].second && dp[i][j].first < next_rest ) ){
                    dp[i][j] = P( next_rest, next_time );
                }
            }
        }
    }

    ll q; cin >> q;
    while(q--) {
        ll s,t; cin >> s >> t;
        s--; t--;
        if( !uf.same(s,t) ) cout << -1 << endl;
        else cout << dp[min(s,t)][max(s,t)].second << endl;
    }
    
    return 0;
}