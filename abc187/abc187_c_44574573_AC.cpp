/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/44574573
 * Submitted at: 2023-08-14 09:15:06
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_c
 * Result: AC
 * Execution Time: 201 ms
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
    vector<string> s(n);
    set<string> st;
    rep(i,n) {
        cin >> s[i];
        st.insert(s[i]);
    }
    rep(i,n) {
        if( s[i][0] == '!' ) continue;
        string ss = "!" + s[i];
        if( st.count(s[i]) && st.count(ss) ) {
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << "satisfiable" << endl;
    
    return 0;
}