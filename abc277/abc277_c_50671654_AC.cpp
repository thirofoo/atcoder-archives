/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/50671654
 * Submitted at: 2024-02-27 10:26:21
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_c
 * Result: AC
 * Execution Time: 108 ms
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
    
    ll n; cin >> n;
    vector<ll> a(n), b(n), comp_a, comp_b;
    rep(i,n) cin >> a[i] >> b[i];
    // 座標圧縮 (配列 a がある想定)
    vector<ll> comp = {1};
    rep(i,n) {
        comp.emplace_back(a[i]);
        comp.emplace_back(b[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    rep(i,n) {
        comp_a.emplace_back(lower_bound(comp.begin(),comp.end(),a[i])-comp.begin());
        comp_b.emplace_back(lower_bound(comp.begin(),comp.end(),b[i])-comp.begin());
    }
    dsu uf(2*n);
    rep(i,n) uf.merge(comp_a[i],comp_b[i]);
    ll ans = 1;
    rep(i,n) {
        if( !uf.same(0,comp_a[i]) ) continue;
        ans = max(ans, a[i]);
    }
    rep(i,n) {
        if( !uf.same(0,comp_b[i]) ) continue;
        ans = max(ans, b[i]);
    }
    cout << ans << endl;
    
    return 0;
}