/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/46211388
 * Submitted at: 2023-10-04 19:44:18
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
 * Result: WA
 * Execution Time: 353 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<P> side;
    vector min_d1(n,vector(n,1e16)), min_d2(n,vector(n,1e16));
    rep(i,m) {
        ll s, t; cin >> s >> t;
        s--; t--;
        min_d1[s][t] = 1;
        side.emplace_back(P(s,t));
    }
    rep(i,n) min_d1[i][i] = 0;
    // warshall-floyd
    rep(k,n)rep(i,n)rep(j,n) min_d1[i][j] = min( min_d1[i][j], min_d1[i][k]+min_d1[k][j] );
    vector f(n,vector<bool>(n,false));
    rep(k,n)rep(i,n)rep(j,n) {
        if( i == j || j == k || k == i ) continue;
        if( min_d1[i][k] == min_d1[i][j] + min_d1[j][k] ) continue;

        if( min_d1[i][k]+min_d1[k][j] == min_d1[i][j] && !f[i][j] ) {
            f[i][j] = true;
            continue;
        }
        min_d2[i][j] = min( min_d2[i][j], min_d1[i][k]+min_d1[k][j] );
    }

    for(auto [s,t]:side) {
        if( min_d1[0][s] + min_d1[t][n-1] + 1 == min_d1[0][n-1] ) {
            cout << ( min_d2[s][t] == 1e16 ? -1 : min_d2[0][n-1] ) << endl;
        }
        else cout << ( min_d1[0][n-1] == 1e16 ? -1 : min_d1[0][n-1] ) << endl;
    }
    
    return 0;
}