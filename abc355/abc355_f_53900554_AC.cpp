/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53900554
 * Submitted at: 2024-05-26 00:21:25
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_f
 * Result: AC
 * Execution Time: 321 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    vector<dsu> d(11, dsu(n));
    vector<ll> cnt(11, n);
    rep(i, n-1) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        reps(j,c,11) {
            if( d[j].same(a, b) ) continue;
            d[j].merge(a, b);
            cnt[j]--;
        }
    }
    rep(i,q) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        reps(j,w,11) {
            if( d[j].same(u, v) ) continue;
            d[j].merge(u, v);
            cnt[j]--;
        }
        ll ans = 0;
        rep(j,11) ans += cnt[j]-1;
        cout << ans << endl;
    }
    
    return 0;
}