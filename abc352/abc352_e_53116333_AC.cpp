/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53116333
 * Submitted at: 2024-05-04 21:36:53
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_e
 * Result: AC
 * Execution Time: 94 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> k(m);
    vector<P> c;
    vector<vector<ll>> a;
    dsu uf(n);
    rep(i,m) {
        ll tc; cin >> k[i] >> tc;
        c.emplace_back(P(tc, i));
        vector<ll> tmp(k[i]);
        rep(j,k[i]) {
            cin >> tmp[j];
            tmp[j]--;
        }
        a.emplace_back(tmp);
    }
    sort(c.begin(), c.end());

    ll ans = 0;
    for(auto [tc, i] : c) {
        rep(j,k[i]-1) {
            if( uf.same(a[i][j], a[i][j+1]) ) continue;
            uf.merge(a[i][j], a[i][j+1]);
            ans += tc;
        }
    }
    if( uf.size(0) == n ) cout << ans << '\n';
    else cout << -1 << '\n';
    
    return 0;
}