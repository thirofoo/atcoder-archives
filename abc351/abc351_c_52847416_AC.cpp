/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52847416
 * Submitted at: 2024-04-27 21:08:09
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_c
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n; cin >> n;
    stack<ll> st;
    rep(i,n) {
        ll a; cin >> a;
        st.push(a);
        while( st.size() >= 2 ) {
            ll x = st.top(); st.pop();
            ll y = st.top(); st.pop();
            if( x == y ) st.push(x+1);
            else {
                st.push(y);
                st.push(x);
                break;
            }
        }
    }
    cout << st.size() << endl;
    
    return 0;
}