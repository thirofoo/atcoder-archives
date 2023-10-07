/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46305860
 * Submitted at: 2023-10-07 21:22:39
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_d
 * Result: AC
 * Execution Time: 976 ms
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
    map<ll,ll> mp;
    rep(i,n) {
        ll s, c; cin >> s >> c;
        mp[s] += c;
    }
    ll ans = 0;
    for(auto [k,v]:mp) {
        if( v%2 == 0 ) mp[2*k] += v/2;
        else {
            ans++;
            v--;
            if( v != 0 ) mp[2*k] += v/2;
        }
    }
    cout << ans << endl;
    
    return 0;
}