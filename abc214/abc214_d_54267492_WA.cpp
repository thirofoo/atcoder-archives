/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/54267492
 * Submitted at: 2024-06-06 14:19:39
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_d
 * Result: WA
 * Execution Time: 16 ms
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
    
    ll n; cin >> n;
    dsu uf(n);
    ll ans = 0;
    rep(i,n-1) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        ans += uf.size(u) * uf.size(v) * w;
        uf.merge(u, v);
    }
    cout << ans << '\n';
    
    return 0;
}