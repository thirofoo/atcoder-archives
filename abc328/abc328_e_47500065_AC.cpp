/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47500065
 * Submitted at: 2023-11-11 22:27:24
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_e
 * Result: AC
 * Execution Time: 30 ms
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
    
    ll n, m, k; cin >> n >> m >> k;
    vector<T> edge;
    rep(i,m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        edge.emplace_back(T(u,v,w));
    }
    ll ans = 1e16;
    auto f = [&](auto self, ll idx, ll num, ll total, dsu uf) -> void {
        if( num == n-1 ) ans = min(ans, total%k);
        else {
            for(ll i=idx; i<m; i++) {
                auto &&[u, v, w] = edge[i];
                if( uf.same(u,v) ) continue;
                dsu nuf = uf;
                nuf.merge(u,v);
                self(self, i+1, num+1, total+w, nuf);
            }
        }
    };
    f(f, 0, 0, 0, dsu(n));
    cout << ans << endl;
    
    return 0;
}