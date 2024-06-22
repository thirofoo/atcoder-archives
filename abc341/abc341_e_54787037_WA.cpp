/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/54787037
 * Submitted at: 2024-06-22 19:22:11
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_e
 * Result: WA
 * Execution Time: 493 ms
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

// SegTree に乗せる型
using S = ll;
// operator (作用素)
S op(S l, S r) {
    return l + r;
}
// 単位元 (op(e, a) = a)
S e() {
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    segtree<S, op, e> seg(n-1);
    rep(i, n-1) seg.set(i, s[i] != s[i+1]);
    while(q--) {
        ll t, l, r; cin >> t >> l >> r;
        if(t == 1) {
            l--, r--;
            s[l] = '0' + (s[l] == '0');
            s[r] = '0' + (s[r] == '0');
            if(l-1 >= 0) seg.set(l-1, s[l-1] != s[l]);
            if(r+1 <  n) seg.set(r, s[r] != s[r+1]);
        }
        else {
            cout << (seg.prod(l-1, r-1) == r-l ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}