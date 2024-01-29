/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/49797471
 * Submitted at: 2024-01-30 02:26:11
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_d
 * Result: AC
 * Execution Time: 209 ms
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
    vector<ll> x(n), y(n);
    map<P,ll> mp;
    rep(i,n) {
        cin >> x[i] >> y[i];
        mp[P(x[i],y[i])]++;
    }
    ll ans = 0;
    rep(i,n) for(ll j=i+1; j<n; j++) {
        if( x[i] == x[j] || y[i] == y[j] ) continue;
        ans += (mp.count(P(x[i],y[j])) && mp.count(P(x[j],y[i])));
    }
    cout << ans/2 << endl;

    return 0;
}