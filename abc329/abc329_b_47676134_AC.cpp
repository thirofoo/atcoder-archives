/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47676134
 * Submitted at: 2023-11-18 21:01:42
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_b
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
    
    ll n; cin >> n;
    set<ll> st;
    rep(i,n) {
        ll a; cin >> a;
        st.insert(a);
    }
    auto itr = st.end();
    itr--; itr--;
    cout << *itr << endl;
    
    return 0;
}