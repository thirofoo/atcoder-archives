/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47719226
 * Submitted at: 2023-11-18 22:12:01
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_e
 * Result: WA
 * Execution Time: 5 ms
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
    
    ll n, m; string s, t; cin >> n >> m >> s >> t;
    ll idx = 0;
    string now = "";
    rep(i,n) now += "#";
    rep(i,n-m+1) {
        ll c1 = 0, c2 = 0;
        for(ll j=i; j<i+m; j++) {
            if( now[j] == '#' ) c1++, c2++;
            else if( now[j] == s[j] ) c1++;
            else c2++;
        }
        // cerr << c1 << " " << c2 << endl;
        if( c1 != m && c2 != m ) continue;

        bool f1 = false, f2 = false; ll c = 0;
        for(ll j=i; j<i+m; j++) {
            if( !f1 ) f1 |= (now[j] == '#' && s[j] != t[j-i] && c2 != m);
            else f2 |= (now[j] == '#' && s[j] == t[j-i]);

            if( (now[j] == '#' || c2 == m) && s[j] == t[j-i] ) c++;
        }
        if( (f1 && f2) || c == 0 ) continue;

        if( c2 == m ) {
            for(ll j=i; j<i+m; j++) now[j] = t[j-i];
        }
        else {
            for(ll j=i; j<i+m; j++) {
                if( now[j] != '#' ) continue;
                now[j] = t[j-i];
            }
        }
        // cerr << now << endl;
    }
    cout << ( now == s ? "Yes" : "No" ) << endl;
    
    return 0;
}