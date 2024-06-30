/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55095229
 * Submitted at: 2024-06-30 22:36:42
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_f
 * Result: WA
 * Execution Time: 951 ms
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
    else if(l.val == r.val) {
        if(l.idx < r.idx) res = l;
        else res = r;
    }
    else res = r;
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
S e() { return {0, 0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> l(n), r(n);
    rep(i, n) {
        cin >> l[i] >> r[i];
        l[i]++;
    }
    vector<ll> comp = {0};
    rep(i, n) {
        comp.emplace_back(l[i]);
        comp.emplace_back(r[i]);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    rep(i, comp.size()) cerr << comp[i] << ' ';
    cerr << '\n';

    vector<vector<ll>> kukan(comp.size(), vector<ll>{});
    rep(i, n) {
        l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
        r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
        kukan[l[i]].emplace_back(i);
    }
    fenwick_tree<ll> fw(comp.size());
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(comp.size());
    rep(i, comp.size()-1) seg.set(i, {i, 0});
    rep(i, n) seg.apply(l[i], r[i], 1);

    rep(i, comp.size()) cerr << seg.prod(i, comp.size()).val << ' ';
    cerr << '\n';

    ll ans = 0, left = 0, right = 0;
    rep(i, comp.size()) {
        for(auto j : kukan[i]) {
            seg.apply(l[j], r[j], -1);
            fw.add(r[j]-1, 1);
        }

        ll cand = seg.prod(i, comp.size()).val + fw.sum(i, comp.size());
        // cerr << i << ' ' << seg.prod(i, comp.size()).val << ' ' << fw.sum(i, comp.size()) << ' ' << cand << '\n';
        if(ans < cand) {
            ans = cand;
            left = comp[i];
            right = comp[seg.prod(i, comp.size()).idx];
            // cerr << left << ' ' << right << ' ' << ans << '\n';
        }

        // rep(i, comp.size()) cerr << fw.sum(i, i+1) << ' ';
        // cerr << '\n';
    }
    cout << left << ' ' << right << ' ' << ans << '\n';
    
    return 0;
}