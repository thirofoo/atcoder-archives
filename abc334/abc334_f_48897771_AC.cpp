/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48897771
 * Submitted at: 2023-12-28 17:17:31
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_f
 * Result: AC
 * Execution Time: 413 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = ld;
using F = ld;
// operator(作用素)
S op(S a,S b){
    return min(a,b);
}
// 遅延データ反映
S mapping(F f,S x){
    return f+x;
}
// 遅延データ作用
F composition(F f,F g){
    return f+g;
}
S e(){ return 1e16; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0.0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, k, sx, sy; cin >> n >> k >> sx >> sy;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> dp(k+n+1);
    dp.set(0, 0.0);
    ll px = sx, py = sy;
    rep(i,n) {
        ld dis1 = sqrt((px-sx)*(px-sx)+(py-sy)*(py-sy)) + sqrt((sx-x[i])*(sx-x[i])+(sy-y[i])*(sy-y[i]));
        dp.set(i+k,dis1+dp.prod(i,i+k));
        ld dis2 = sqrt((px-x[i])*(px-x[i])+(py-y[i])*(py-y[i]));
        dp.apply(i+1,i+k,dis2);
        px = x[i], py = y[i];
    }
    cout << dp.prod(n,n+k) + sqrt((px-sx)*(px-sx)+(py-sy)*(py-sy)) << '\n';
    
    return 0;
}