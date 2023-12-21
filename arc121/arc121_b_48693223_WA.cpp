/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc121/submissions/48693223
 * Submitted at: 2023-12-21 19:02:28
 * Problem URL: https://atcoder.jp/contests/arc121/tasks/arc121_b
 * Result: WA
 * Execution Time: 40 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> a(3);
    rep(i,2*n) {
        ll ta; char c; cin >> ta >> c;
        if( c == 'R' ) a[0].emplace_back(ta);
        else if( c == 'G' ) a[1].emplace_back(ta);
        else a[2].emplace_back(ta);
    }
    rep(i,3) sort(a[i].begin(), a[i].end());

    ll rg = 1e16, rb = 1e16, gb = 1e16;
    for(ll i=0; i<a[0].size(); i++) {
        auto itr = lower_bound(a[1].begin(), a[1].end(), a[0][i]);
        ll cand = 1e16;
        if( itr != a[1].end() ) cand = min(cand, abs(*itr - a[0][i]));
        if( itr != a[1].begin() ) cand = min(cand, abs(a[0][i] - *(itr-1)));
        rg = min(rg,cand);
    }
    for(ll i=0; i<a[0].size(); i++) {
        auto itr = lower_bound(a[2].begin(), a[2].end(), a[0][i]);
        ll cand = 1e16;
        if( itr != a[2].end() ) cand = min(cand, abs(*itr - a[0][i]));
        if( itr != a[2].begin() ) cand = min(cand, abs(a[0][i] - *(itr-1)));
        rb = min(rb,cand);
    }
    for(ll i=0; i<a[2].size(); i++) {
        auto itr = lower_bound(a[1].begin(), a[1].end(), a[2][i]);
        ll cand = 1e16;
        if( itr != a[1].end() ) cand = min(cand, abs(*itr - a[2][i]));
        if( itr != a[1].begin() ) cand = min(cand, abs(a[2][i] - *(itr-1)));
        gb = min(gb,cand);
    }
    ll ans = 0;
    if( a[0].size()%2 == 1 && a[1].size()%2 == 1 ) ans += rg;
    if( a[0].size()%2 == 1 && a[2].size()%2 == 1 ) ans += rb;
    if( a[1].size()%2 == 1 && a[2].size()%2 == 1 ) ans += gb;
    cout << ans << endl;
    
    return 0;
}