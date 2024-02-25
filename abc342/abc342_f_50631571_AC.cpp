/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50631571
 * Submitted at: 2024-02-25 15:40:56
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_f
 * Result: AC
 * Execution Time: 768 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// S が data, F が lazy
using S = struct {
    ll size;
    ld val;
};
using F = ld;
// operator (作用素)
S op(S l,S r) {
    return {l.size+r.size, l.val+r.val};
}
// 遅延データ反映
S mapping(F f,S x) {
    return {x.size, x.val+f*x.size};
}
// 遅延データ作用 ※ g → f の順
F composition(F f,F g) {
    return f+g;
}
S e() { return {0, 0.0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0.0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, l, d; cin >> n >> l >> d;
    lazy_segtree<S, op, e, F, mapping, composition, id> dealer(n+d+1), player(n+1);
    rep(i,n+d+1) dealer.set(i, {1, 0.0});
    rep(i,n+1) player.set(i, {1, 0.0});
    dealer.set(0, {1, 1.0});
    rep(i,l) {
        ld np = dealer.get(i).val / d;
        dealer.set(i, {1, 0.0});
        dealer.apply(i+1, i+d+1, np);
    }
    ld dealer_burst = 0.0;
    dealer_burst = dealer.prod(n+1, n+d+1).val;
    // cerr << dealer_burst << endl;

    for(ll i=n; i>=0; i--) {
        // 振らない場合の勝率
        ld cand = dealer.prod(0,i).val + dealer_burst;

        // 振る場合の勝率
        cand = max(cand, player.prod(i+1,min(i+d+1,n+1)).val / d);
        player.set(i, {1, cand});
    }
    cout << player.get(0).val << endl;
    
    return 0;
}