/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc046/submissions/44399217
 * Submitted at: 2023-08-09 09:12:05
 * Problem URL: https://atcoder.jp/contests/abc046/tasks/abc046_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll a,b,c; cin >> a >> b >> c;
    set<ll> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    cout << st.size() << endl;
    
    return 0;
}