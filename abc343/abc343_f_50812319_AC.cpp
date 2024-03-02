/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50812319
 * Submitted at: 2024-03-02 21:37:15
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_f
 * Result: AC
 * Execution Time: 973 ms
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

// SegTree に乗せる型
using S = struct {
    ll m1;
    ll n1;
    ll m2;
    ll n2;
};
// operator (作用素)
S op(S l,S r) {
    map<ll,ll> mp;
    mp[l.m1] += l.n1;
    mp[l.m2] += l.n2;
    mp[r.m1] += r.n1;
    mp[r.m2] += r.n2;
    // 上位2つを取り出す
    auto it = mp.end();
    it--;
    auto [m1,n1] = *it;
    it--;
    auto [m2,n2] = *it;
    return {m1,n1,m2,n2};
}
// 単位元 (op(e,a) = a)
S e() {
    return {0,0,0,0};
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    segtree<S,op,e> seg(n);
    rep(i,n) {
        cin >> a[i];
        seg.set(i,{a[i],1,0,0});
    }
    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll p, x; cin >> p >> x; p--;
            seg.set(p,{x,1,0,0});
        }
        else {
            ll l, r; cin >> l >> r; l--;
            auto [m1,n1,m2,n2] = seg.prod(l,r);
            cout << n2 << endl;
        }
    }
    
    return 0;
}