/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47610345
 * Submitted at: 2023-11-16 13:24:13
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_a
 * Result: AC
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
    
    ll n; cin >> n;
    set<ll> st;
    rep(i,n) {
        ll a; cin >> a;
        st.insert(a);
    }
    cout << (st.size() == 1 ? "Yes" : "No") << endl;
    
    return 0;
}