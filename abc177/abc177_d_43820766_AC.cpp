/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc177/submissions/43820766
 * Submitted at: 2023-07-22 16:48:50
 * Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_d
 * Result: AC
 * Execution Time: 49 ms
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
    
    ll n,m; cin >> n >> m;
    dsu uf(n);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--; b--;
        uf.merge(a,b);
    }
    vector g = uf.groups();
    ll ans = g[0].size();
    rep(i,g.size()) ans = max(ans, (ll)g[i].size());
    cout << ans << endl;
    
    return 0;
}