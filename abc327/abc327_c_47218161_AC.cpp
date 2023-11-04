/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47218161
 * Submitted at: 2023-11-04 21:06:31
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_c
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n = 9;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(i,n) {
        set<ll> st;
        rep(j,n) st.insert(a[i][j]);
        if( st.size() != 9 ) return cout << "No" << endl, 0;
    }
    rep(j,n) {
        set<ll> st;
        rep(i,n) st.insert(a[i][j]);
        if( st.size() != 9 ) return cout << "No" << endl, 0;
    }
    rep(i,n/3) {
        rep(j,n/3) {
            set<ll> st;
            rep(k,n/3) rep(l,n/3) st.insert(a[i*3+k][j*3+l]);
            if( st.size() != 9 ) return cout << "No" << endl, 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}