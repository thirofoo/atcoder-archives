/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/45783941
 * Submitted at: 2023-09-22 10:03:33
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_d
 * Result: AC
 * Execution Time: 217 ms
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
    
    ll q; cin >> q;
    multiset<ll> st;
    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll x; cin >> x;
            st.insert(x);
        }
        else if( t == 2 ) {
            ll x, k; cin >> x >> k;
            auto itr = st.upper_bound(x);
            bool f = true;
            while( k-- ) {
                if( itr == st.begin() ) {
                    f = false;
                    break;
                }
                itr--;
            }
            cout << (f ? *itr : -1) << endl;
        }
        else {
            ll x, k; cin >> x >> k; k--;
            auto itr = st.lower_bound(x);
            bool f = true;
            while( k-- ) {
                if( itr == st.end() ) {
                    f = false;
                    break;
                }
                itr++;
            }
            if( itr == st.end() ) f = false;
            cout << (f ? *itr : -1) << endl;
        }
    }
    
    return 0;
}