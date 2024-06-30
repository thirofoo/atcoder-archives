/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55104550
 * Submitted at: 2024-07-01 01:41:18
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_f
 * Result: AC
 * Execution Time: 373 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// S:実 F:遅延
using S = struct {
    ll idx;
    ll val;
};
using F = ll;
// operator (作用素)
S op(S l, S r) {
    S res;
    if(l.val > r.val) res = l;
    else if(l.val < r.val) res = r;
    else  {
        if(l.idx < r.idx) res = l;
        else res = r;
    }
    return res;
}
// 遅延データ反映
S mapping(F f, S x) {
   return {x.idx, x.val + f};
}
// 遅延データ作用 ※ f(g(x))
F composition(F f, F g) {
   return f + g;
}
S e() { return {INF, 0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    vector<ll> comp = {0, INF};
    rep(i, n) {
        comp.emplace_back(l[i]);
        comp.emplace_back(l[i]+1);
        comp.emplace_back(r[i]);
        comp.emplace_back(r[i]+1);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    ll size = comp.size();
    vector kukan_l(size, vector<ll>{}), kukan_r(size, vector<ll>{});
    rep(i, n) {
        l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
        r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
        kukan_l[l[i]].emplace_back(i);
        kukan_r[r[i]].emplace_back(i);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(size);
    rep(i, size) seg.set(i, {i, 0});
    rep(i, n) seg.apply(l[i]+1, r[i], 1);

    ll ans = -1, left = 0, right = 0;
    rep(i, size-1) {
        for(auto &&j : kukan_l[i]) seg.apply(l[j]+1, r[j], -1);
        for(auto &&j : kukan_r[i]) seg.apply(r[j]+1, size, -1);
        S cand = seg.prod(i+1, size);
        if(ans < cand.val && comp[cand.idx] <= 1e9) {
            ans = cand.val;
            left = comp[i];
            right = comp[cand.idx];
        }
        for(auto &&j : kukan_l[i]) seg.apply(r[j]+1, size, 1);
    }
    cout << left << ' ' << right << '\n';
    
    return 0;
}