/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc147/submissions/45930035
 * Submitted at: 2023-09-25 09:28:22
 * Problem URL: https://atcoder.jp/contests/arc147/tasks/arc147_a
 * Result: AC
 * Execution Time: 455 ms
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
    multiset<ll> st;
    rep(i,n) {
        ll a; cin >> a;
        st.insert(a);
    }
    ll ans = 0;
    while( st.size() > 1 ) {
        ll e1 = *st.begin(), e2;
        auto itr = st.end();
        itr--;
        e2 = *itr;
        if( e2%e1 != 0 ) st.insert(e2%e1);
        st.erase(itr);
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}