/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/50217374
 * Submitted at: 2024-02-12 10:07:41
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_d
 * Result: AC
 * Execution Time: 444 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    
    ll q; cin >> q;
    ll n = 1LL << 20;
    vector<ll> a(n, -1);
    set<ll> st;
    rep(i,n) st.insert(i);
    while( q-- ) {
        ll t, x; cin >> t >> x;
        if( t == 1 ) {
            ll start = x%n;
            auto itr = st.lower_bound(start);
            if( itr == st.end() ) itr = st.lower_bound(0);
            a[*itr] = x;
            st.erase(itr);
        }
        else cout << a[x%n] << endl;
    }
    
    return 0;
}