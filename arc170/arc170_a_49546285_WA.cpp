/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc170/submissions/49546285
 * Submitted at: 2024-01-21 21:28:44
 * Problem URL: https://atcoder.jp/contests/arc170/tasks/arc170_a
 * Result: WA
 * Execution Time: 4 ms
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
    vector<ll> ca, cb;
    rep(i,n) {
        if( s[i] != t[i] ) {
            if( s[i] == 'A' ) ca.push_back(i);
            else cb.push_back(i);
        }
    }
    ll ans = 0, ai = 0, bi = 0;
    while( ai < ca.size() && bi < cb.size() ) {
        if( cb[bi] < ca[ai] ) {
            ans++;
            bi++;
            ai++;
        }
        else {
            ans++;
            ai++;
        }
    }
    ans += ca.size() - ai + cb.size() - bi;
    cout << ans << endl;
    
    return 0;
}