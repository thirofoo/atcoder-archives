/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc165/submissions/45684598
 * Submitted at: 2023-09-17 22:58:50
 * Problem URL: https://atcoder.jp/contests/arc165/tasks/arc165_c
 * Result: WA
 * Execution Time: 309 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<vector<P>> Graph(n);
    rep(i,m) {
        ll a, b, w; cin >> a >> b >> w;
        a--; b--;
        Graph[a].push_back(P(b,w));
    }

    ll left = 0, right = 1e16;
    while( right-left > 1 ) {
        ll mid = (right+left)/2;
        dsu uf(n);
        bool f = true;
        rep(i,n) {
            for(auto [j,w]:Graph[i]) {
                if( w < mid ) {
                    if( uf.same(i,j) ) f = false;
                    else uf.merge(i,j);
                }
            }
        }
        if(f) left = mid;
        else right = mid;
    }
    cout << left << endl;

    
    return 0;
}