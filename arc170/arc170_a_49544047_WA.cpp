/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49544047
 * Submitted at: 2024-01-21 21:18:50
 * Problem URL: https://atcoder.jp/contests/arc170/tasks/arc170_a
 * Result: WA
 * Execution Time: 2208 ms
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
    
    ll n; string s, t; cin >> n >> s >> t;
    if( s[0] == 'A' && t[0] == 'B' ) {
        cout << -1 << endl;
        return 0;
    }
    if( s.back() == 'B' && t.back() == 'A' ) {
        cout << -1 << endl;
        return 0;
    }
    set<ll> ca, cb;
    rep(i,n) {
        if( s[i] != t[i] ) {
            if( s[i] == 'A' ) ca.insert(i);
            else cb.insert(i);
        }
    }
    ll ans = 0;
    rep(i,n) {
        auto itr = ca.lower_bound(*cb.begin());
        if( itr != ca.end() ) {
            ca.erase(itr);
            cb.erase(cb.begin());
            ans++;
        }
    }
    ans += ca.size() + cb.size();
    cout << ans << endl;
    
    return 0;
}