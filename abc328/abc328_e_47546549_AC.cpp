/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47546549
 * Submitted at: 2023-11-13 15:44:42
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_e
 * Result: AC
 * Execution Time: 122 ms
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
    
    ll n, m, k, ans = 1e16; cin >> n >> m >> k;
    vector<T> edge;
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edge.emplace_back(T(u,v,w));
    }
    vector<ll> p;
    rep(i,n-1) p.emplace_back(1);
    while( p.size() != m ) p.emplace_back(0);
    sort(p.begin(), p.end());
    do {
        dsu uf(n);
        ll cand = 0;
        rep(i,m) {
            if( p[i] ) {
                auto &&[u,v,w] = edge[i];
                uf.merge(u,v);
                cand += w;
            }
        }
        if( uf.size(0) != n ) continue;
        ans = min(ans, cand%k);
    } while( next_permutation(p.begin(), p.end()) );
    cout << ans << endl;
    
    return 0;
}