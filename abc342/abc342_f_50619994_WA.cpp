/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50619994
 * Submitted at: 2024-02-25 02:12:10
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_f
 * Result: WA
 * Execution Time: 2210 ms
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

// S が data, F が lazy
using S = ld;
using F = ld;
// operator (作用素)
S op(S l,S r) {
    return l+r;
}
// 遅延データ反映
S mapping(F f,S x) {
    return f+x;
}
// 遅延データ作用 ※ g → f の順
F composition(F f,F g) {
    return f+g;
}
S e() { return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, l, d; cin >> n >> l >> d;
    // 諦めが早い ⇒ シンプルな負けが多い
    // 諦めが悪い ⇒ バーストして負けることが多い
    // ⇒ 極値がありそうだから三分探索？
    lazy_segtree<S, op, e, F, mapping, composition, id> dealer(n+2), player(n+2);
    dealer.set(0, 1.0);
    rep(i,l) {
        ld np = dealer.get(i) / d;
        dealer.set(i, 0.0);
        dealer.apply(i+1, min(i+d+1, n+1), np);
        dealer.apply(n+1, n+2, max((i+d+1-(n+1)),0ll)*np); // バースト
    }
    // cerr << "dealer" << endl;
    // rep(i,n+2) cerr << dealer.get(i) << " ";
    // cerr << endl;

    auto f = [&](ll x) -> ld {
        player = lazy_segtree<S, op, e, F, mapping, composition, id>(n+2);
        player.set(0, 1.0);
        rep(i,x) {
            ld np = player.get(i) / d;
            player.set(i, 0.0);
            player.apply(i+1, min(i+d+1, n+1), np);
            player.apply(n+1, n+2, max((i+d+1-(n+1)),0ll)*np); // バースト
        }
        // cerr << "player" << endl;
        // rep(i,n+2) cerr << player.get(i) << " ";
        // cerr << endl << endl;
        // dealer : バースト, player : バーストしない初期確率
        ld res = dealer.get(n+1) * (1.0 - player.get(n+1));
        rep(i,n+1) res += dealer.prod(0,i) * player.get(i);
        // cerr << "res: " << res << endl;
        return res;
    };

    // 三分探索 (整数値ver)
    ll left = 0, right = n;
    while( right-left > 2 ){
        ld c1 = (left + left + right) / 3;
        ld c2 = (left + right + right) / 3;
        // cerr << left << " " << right << endl;
        if( f(c1) >= f(c2) ) right = c1;
        else left = c2;
    }
    cout << max(f(left), f(left+1)) << endl;
    
    return 0;
}