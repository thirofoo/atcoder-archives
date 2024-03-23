/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc346/submissions/51551083
 * Submitted at: 2024-03-23 21:05:28
 * Problem URL: https://atcoder.jp/contests/abc346/tasks/abc346_c
 * Result: AC
 * Execution Time: 71 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    set<ll> st;
    rep(i, n) {
        ll a; cin >> a;
        st.insert(a);
    }
    ll ans = (1+k) * k / 2;
    for(auto x : st) {
        if( x <= k ) ans -= x;
    }
    cout << ans << endl;
    
    return 0;
}