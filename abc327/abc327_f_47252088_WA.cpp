/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47252088
 * Submitted at: 2023-11-04 21:48:29
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_f
 * Result: WA
 * Execution Time: 198 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = ll;
using F = ll;
// operator(作用素)
S op(S a,S b){
    return max(a,b);
}
// 遅延データ反映
S mapping(F f,S x){
    return f+x;
}
// 遅延データ作用
F composition(F f,F g){
    return f+g;
}
S e(){ return 0ll; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0ll; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, d, w; cin >> n >> d >> w;
    vector<vector<ll>> fruit(300000);
    rep(i,n) {
        ll t, x; cin >> t >> x;
        fruit[t].emplace_back(x);
    }
    lazy_segtree<S,op,e,F,mapping,composition,id> lsg(300000);
    for(int i=1; i<d; i++) {
        for(auto fp:fruit[i]) {
            lsg.apply(max(0ll,fp-w), min(300000ll,fp+w+1), 1ll);
        }
    }
    ll ans = lsg.all_prod();
    for(int i=d; i<300000; i++) {
        for(auto fp:fruit[i-d+1]) lsg.apply(max(0ll,fp-w), min(300000ll,fp+w+1), -1ll);
        for(auto fp:fruit[i]) lsg.apply(max(0ll,fp-w), min(300000ll,fp+w+1), 1ll);
        ans = max(ans, lsg.all_prod());
    }
    cout << ans << endl;
    
    return 0;
}