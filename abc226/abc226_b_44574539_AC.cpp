/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/44574539
 * Submitted at: 2023-08-14 09:11:28
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_b
 * Result: AC
 * Execution Time: 187 ms
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
    set<vector<ll>> st;
    rep(i,n) {
        ll l; cin >> l;
        vector<ll> tmp(l);
        rep(i,l) cin >> tmp[i];
        st.insert(tmp);
    }
    cout << st.size() << endl;
    
    return 0;
}