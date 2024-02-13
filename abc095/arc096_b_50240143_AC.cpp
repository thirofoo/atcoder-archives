/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc095/submissions/50240143
 * Submitted at: 2024-02-13 11:48:14
 * Problem URL: https://atcoder.jp/contests/abc095/tasks/arc096_b
 * Result: AC
 * Execution Time: 158 ms
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

// S が data, F が lazy
using S = ll;
using F = ll;
// operator (作用素)
S op(S l,S r) {
    return max(l,r);
}
// 遅延データ反映
S mapping(F f,S x) {
    return x+f;
}
// 遅延データ作用 ※ g → f の順
F composition(F f,F g) {
    return f+g;
}
S e() { return -1e16; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

ll n, c;
vector<ll> x, v;

ll solve() {
    // n 個の区間 & Start の n+1 地点で管理したほうが楽そう
    vector<ll> nx, nv;
    rep(i,n) {
        if( i == 0 ) nx.emplace_back(x[i]);
        else nx.emplace_back(abs(x[i]-x[i-1]));
    }
    nx.emplace_back(c-x[n-1]);
    rep(i,n) nv.emplace_back(v[i]);
    nv.emplace_back(0);
    vector<ll> rx(1,0), rv(1,0);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(2*(n+1)+1);
    rep(i,2*(n+1)+1)  {
        rx.emplace_back(nx[i%(n+1)]+rx.back());
        rv.emplace_back(nv[i%(n+1)]+rv.back());
        seg.set(i,rv[i]-rx[i]);
    }
    
    ll ans = 0;
    // 左 ⇒ 右 の順で訪問する時の左を全探索
    for(ll i=1; i<=n+1; i++) {
        seg.apply(i,2*(n+1)+1, rx[i]-rx[i-1]);
        
        ll cost = -(c-rx[i]); // Start までの距離
        cost += seg.prod(i,i+n+1); // 左から右までの最大値;
        ans = max(ans,cost);

        seg.apply(i,2*(n+1)+1, -v[i-1]);
    }
    return ans;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> c;
    x.assign(n,0);  
    v.assign(n,0);
    rep(i,n) cin >> x[i] >> v[i];

    ll ans = 0;
    ans = max(ans,solve());
    reverse(x.begin(), x.end());
    rep(i,n) x[i] = c-x[i];
    reverse(v.begin(), v.end());
    ans = max(ans,solve());
    cout << ans << '\n';
    
    return 0;
}