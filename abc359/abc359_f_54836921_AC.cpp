/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54836921
 * Submitted at: 2024-06-22 22:10:55
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_f
 * Result: AC
 * Execution Time: 74 ms
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
using S = struct {
    ll idx;
    ll val;
};
// operator (作用素)
S op(S l, S r) {
    if(l.val < r.val) return l;
    else return r;
}
// 単位元 (op(e, a) = a)
S e() {
    return {INF, INF};
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll ans = 0;
    vector<ll> deg(n, 0);
    segtree<S, op, e> seg(n);
    seg.set(0, {0, a[0]});
    reps(i, 1, n) {
        S s = seg.prod(0, i);
        ans += s.val + a[i];

        deg[s.idx]++;
        deg[i]++;

        seg.set(s.idx, {s.idx, (deg[s.idx]+1) * (deg[s.idx]+1) * a[s.idx] - deg[s.idx] * deg[s.idx] * a[s.idx]});
        seg.set(i, {i, 3 * a[i]});
        // cout << ans << '\n';
        // rep(i, n) cerr << deg[i] << ' ';
        // cerr << '\n';
    }
    cout << ans << '\n';
    
    return 0;
}