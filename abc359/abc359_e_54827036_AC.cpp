/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc359/submissions/54827036
 * Submitted at: 2024-06-22 21:47:01
 * Problem URL: https://atcoder.jp/contests/abc359/tasks/abc359_e
 * Result: AC
 * Execution Time: 183 ms
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
    return max(l, r);
}
// 単位元 (op(e, a) = a)
S e() {
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> h(n), th;
    rep(i, n) cin >> h[i];

    th = h;
    th.emplace_back(INF);
    sort(th.begin(), th.end());
    th.erase(unique(th.begin(), th.end()), th.end());
    map<ll, ll> comp_h;
    rep(i, th.size()) comp_h[th[i]] = i;

    // 直近で自分より塀が高い場所が求められれば良さそう
    segtree<S, op, e> seg(th.size());
    seg.set(th.size()-1, 0);
    vector<ll> dp(n+1, 0);
    reps(i, 1, n+1) {
        ll idx = seg.prod(comp_h[h[i-1]]+1, th.size());
        dp[i] = h[i-1] * (i-idx) - (dp[i-1] - dp[idx]) + dp[i-1] + (idx == 0 ? 1 : 0);
        // cerr << h[i-1] * (i-idx) << ' ' << dp[i-1] << " " << dp[idx] << " " << idx << '\n';
        seg.set(comp_h[h[i-1]], i);
    }
    reps(i, 1, n+1) cout << dp[i] << ' ';
    cout << '\n';
    
    return 0;
}