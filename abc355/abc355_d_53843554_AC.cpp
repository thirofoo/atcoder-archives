/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc355/submissions/53843554
 * Submitted at: 2024-05-25 21:12:30
 * Problem URL: https://atcoder.jp/contests/abc355/tasks/abc355_d
 * Result: AC
 * Execution Time: 358 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> l(n), r(n), comp;
    rep(i,n) {
        cin >> l[i] >> r[i];
        comp.push_back(l[i]);
        comp.push_back(r[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );

    vector<P> lr;
    rep(i,n) {
        l[i] = lower_bound(comp.begin(),comp.end(),l[i]) - comp.begin();
        r[i] = lower_bound(comp.begin(),comp.end(),r[i]) - comp.begin();
        lr.emplace_back(P(l[i],r[i]));
    }

    sort(lr.begin(),lr.end());
    fenwick_tree<ll> fw(comp.size());
    ll ans = 0;
    rep(i,n) {
        auto [li,ri] = lr[i];
        ans += fw.sum(li, comp.size());
        fw.add(ri,1);
    }
    cout << ans << endl;
    
    return 0;
}