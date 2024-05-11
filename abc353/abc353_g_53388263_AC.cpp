/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc353/submissions/53388263
 * Submitted at: 2024-05-12 00:12:26
 * Problem URL: https://atcoder.jp/contests/abc353/tasks/abc353_g
 * Result: AC
 * Execution Time: 87 ms
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
S op(S l,S r) { return max(l,r); }
S e() { return -2e18; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC
    // 傾き不変の等差数列の場合は左端・右端基準のポテンシャルを付与した値を segtree に格納
    // ⇒ 区間 max を取った後に無駄なポテンシャル分を引けば真の値が求まる

    ll n, c, m; cin >> n >> c >> m;
    segtree<S, op, e> lsg(n), rsg(n);
    lsg.set(0, 0);
    rsg.set(0, 0);
    rep(i,m) {
        ll t, p; cin >> t >> p;
        ll l_max = lsg.prod(0, t) - (t-1)*c + p;
        ll r_max = rsg.prod(t, n) - (n-t)*c + p;
        ll max_v = max(l_max, r_max);
        lsg.set(t-1, max_v + (t-1)*c);
        rsg.set(t-1, max_v + (n-t)*c);
    }
    ll ans = -2e18;
    rep(i,n) ans = max({ans, lsg.get(i)-i*c, rsg.get(i)-(n-i-1)*c});
    cout << ans << '\n';
    
    return 0;
}