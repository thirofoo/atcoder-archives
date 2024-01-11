/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/49216068
 * Submitted at: 2024-01-11 18:52:56
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_a
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
    
    ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    set<ll> st;
    st.insert(a);
    st.insert(b);
    st.insert(c);
    st.insert(d);
    st.insert(e);
    cout << st.size() << endl;

    
    return 0;
}