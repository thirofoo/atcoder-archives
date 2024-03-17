/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc174/submissions/51388189
 * Submitted at: 2024-03-17 21:23:49
 * Problem URL: https://atcoder.jp/contests/arc174/tasks/arc174_a
 * Result: AC
 * Execution Time: 45 ms
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
using S = ll;
// operator (作用素)
S op1(S l,S r) {
    return max(l,r);
}
// 単位元 (op(e,a) = a)
S e1() {
    return -1e16;
}
S op2(S l,S r) {
    return min(l,r);
}
// 単位元 (op(e,a) = a)
S e2() {
    return 1e16;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, c; cin >> n >> c;
    vector<ll> a(n+1, 0);
    ll ans = 0, total = 0;
    rep(i,n) {
        cin >> a[i+1];
        total += a[i+1];
        a[i+1] += a[i];
    }
    ans = total;
    segtree<S, op1, e1> seg1(a);
    segtree<S, op2, e2> seg2(a);
    rep(i,n+1) {
        if( c > 0 ) {
            ll max_ele = seg1.prod(i,n+1);
            ans = max(ans, total - (max_ele-a[i]) + (max_ele-a[i])*c);
        }
        else {
            ll min_ele = seg2.prod(i,n+1);
            ans = max(ans, total - (min_ele-a[i]) + (min_ele-a[i])*c);
        }
    }
    cout << ans << '\n';
    
    return 0;
}