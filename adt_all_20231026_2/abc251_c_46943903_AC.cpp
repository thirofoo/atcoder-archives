/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46943903
 * Submitted at: 2023-10-26 18:43:39
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc251_c
 * Result: AC
 * Execution Time: 71 ms
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
    set<string> st;
    ll ans = -1, idx = 0;
    rep(i,n) {
        string s; ll t; cin >> s >> t;
        if( st.count(s) ) continue;
        if( ans < t ) {
            ans = t;
            idx = i+1;
        }
        st.insert(s);
    }
    cout << idx << endl;
    
    return 0;
}