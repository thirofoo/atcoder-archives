/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52863900
 * Submitted at: 2024-04-27 21:34:51
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_f
 * Result: AC
 * Execution Time: 505 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // 座圧して map を持っておく
    vector<ll> comp;
    rep(i,n) comp.emplace_back(a[i]);
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    map<ll,ll> mp;
    rep(i,n) mp[comp[i]] = i;

    fenwick_tree<ll> fw1(n), fw2(n); // fw1 は要素、fw2 は要素数
    ll ans = 0;
    rep(i,n) {
        ll x = mp[a[i]];
        ans += fw2.sum(0,x)*a[i] - fw1.sum(0,x);
        fw1.add(x, a[i]);
        fw2.add(x, 1);
    }
    cout << ans << endl;
    
    return 0;
}