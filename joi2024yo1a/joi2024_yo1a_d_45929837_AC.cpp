/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/joi2024yo1a/submissions/45929837
 * Submitted at: 2023-09-25 09:13:30
 * Problem URL: https://atcoder.jp/contests/joi2024yo1a/tasks/joi2024_yo1a_d
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
    for(auto ele:st) cout << ele << endl;
    
    return 0;
}