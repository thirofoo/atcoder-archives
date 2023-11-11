/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47459250
 * Submitted at: 2023-11-11 21:04:52
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_b
 * Result: WA
 * Execution Time: 2 ms
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
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    ll ans = 0;
    rep(i,n) {
        for(ll j=1; j<=d[i]; j++) {
            set<ll> st;
            st.insert((i+1)%10);
            if( i+1 >= 10 ) st.insert(((i+1)/10)%10);
            st.insert(j%10);
            if( j >= 10 ) st.insert((j/10)%10);
            if( st.size() == 1 ) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}