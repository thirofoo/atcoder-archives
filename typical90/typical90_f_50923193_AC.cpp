/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50923193
 * Submitted at: 2024-03-05 17:54:34
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_f
 * Result: AC
 * Execution Time: 10 ms
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
    ll num;
    ll idx;
};
// operator (作用素)
S op(S l,S r) {
    if( l.num < r.num ) return l;
    else if( r.num < l.num ) return r;

    if( l.idx == -1 ) return r;
    return ( l.idx < r.idx ? l : r);
}
// 単位元 (op(e,a) = a)
S e() {
    return S{LLONG_MAX, -1};
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, rest; string s; cin >> n >> rest >> s;
    segtree<S, op, e> sg(n);
    rep(i,n) sg.set(i, S{(ll)(s[i]-'a'), i});
    ll now = 0;
    string ans = "";
    while( now != n && rest > 0 ) {
        // cerr << now << " " << n-rest+1 << endl;
        auto [num, idx] = sg.prod(now, n-rest+1);
        now = idx+1;
        rest--;
        ans += (char)('a' + num);
    }
    cout << ans << endl;
    
    return 0;
}