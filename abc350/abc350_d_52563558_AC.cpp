/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/52563558
 * Submitted at: 2024-04-20 21:11:33
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_d
 * Result: AC
 * Execution Time: 33 ms
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
    vector<ll> a(m), b(m);
    dsu uf(n);
    rep(i,m) {
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        uf.merge(a[i], b[i]);
    }
    vector g = uf.groups();
    ll ans = 0;
    for(auto x : g) {
        ll sz = x.size();
        ans += sz*(sz-1)/2;
    }
    ans -= m;
    cout << ans << '\n';
    
    return 0;
}