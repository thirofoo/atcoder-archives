/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/45739917
 * Submitted at: 2023-09-20 09:19:00
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_b
 * Result: AC
 * Execution Time: 361 ms
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
    
    ll n, w; cin >> n >> w;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    set<ll> st;
    rep(i,n) {
        if( a[i] > w ) continue;
        st.insert( a[i] );
    }
    rep(i,n) {
        for(ll j=i+1;j<n;j++) {
            if( a[i] + a[j] > w ) continue;
            st.insert( a[i] + a[j] );
        }
    }
    rep(i,n) {
        for(ll j=i+1;j<n;j++) {
            for(ll k=j+1;k<n;k++) {
                if( a[i] + a[j] + a[k] > w ) continue;
                st.insert( a[i] + a[j] + a[k] );
            }
        }
    }
    cout << st.size() << endl;
    
    return 0;
}