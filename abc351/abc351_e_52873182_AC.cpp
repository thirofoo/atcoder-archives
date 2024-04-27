/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52873182
 * Submitted at: 2024-04-27 21:57:36
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_e
 * Result: AC
 * Execution Time: 257 ms
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
    vector<ll> x(n), y(n);
    vector<P> odd, even;
    rep(i,n) {
        cin >> x[i] >> y[i];
        if( (x[i]+y[i])%2 == 0 ) even.push_back({x[i], y[i]});
        else odd.push_back({x[i], y[i]});
    }
    // 45 度回転
    vector<ll> odd_x, odd_y, even_x, even_y;
    auto rot = [&](ll x, ll y) -> P { return {x+y, x-y}; };
    rep(i,odd.size()) {
        auto [x, y] = odd[i];
        auto [nx, ny] = rot(x, y);
        odd_x.emplace_back((nx-1)/2);
        odd_y.emplace_back((ny+1)/2);
    }
    rep(i,even.size()) {
        auto [x, y] = even[i];
        auto [nx, ny] = rot(x, y);
        even_x.emplace_back(nx/2);
        even_y.emplace_back(ny/2);
    }
    sort(odd_x.begin(), odd_x.end());
    sort(odd_y.begin(), odd_y.end());
    sort(even_x.begin(), even_x.end());
    sort(even_y.begin(), even_y.end());

    // 座圧して map を持っておく
    vector<ll> comp;
    rep(i,odd_x.size()) comp.emplace_back(odd_x[i]);
    rep(i,odd_y.size()) comp.emplace_back(odd_y[i]);
    rep(i,even_x.size()) comp.emplace_back(even_x[i]);
    rep(i,even_y.size()) comp.emplace_back(even_y[i]);
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    map<ll,ll> mp;
    rep(i,comp.size()) mp[comp[i]] = i;

    fenwick_tree<ll> fw(comp.size());
    ll ans = 0;
    rep(i,odd_x.size()) {
        ans += odd_x[i]*i - fw.sum(0, mp[odd_x[i]]+1);
        fw.add(mp[odd_x[i]], odd_x[i]);
        // cerr << "ans: " << ans << endl;
        // cerr << "odd_x[i]: " << odd_x[i] << endl;
    }
    // cerr << endl;
    fw = fenwick_tree<ll>(comp.size());
    rep(i,odd_y.size()) {
        ans += odd_y[i]*i - fw.sum(0, mp[odd_y[i]]+1);
        fw.add(mp[odd_y[i]], odd_y[i]);
        // cerr << ans << endl;
    }
    // cerr << endl;
    fw = fenwick_tree<ll>(comp.size());
    rep(i,even_x.size()) {
        ans += even_x[i]*i - fw.sum(0, mp[even_x[i]]+1);
        fw.add(mp[even_x[i]], even_x[i]);
        // cerr << ans << endl;
    }
    // cerr << endl;
    fw = fenwick_tree<ll>(comp.size());
    rep(i,even_y.size()) {
        ans += even_y[i]*i - fw.sum(0, mp[even_y[i]]+1);
        fw.add(mp[even_y[i]], even_y[i]);
    }
    cout << ans << endl;
    
    return 0;
}