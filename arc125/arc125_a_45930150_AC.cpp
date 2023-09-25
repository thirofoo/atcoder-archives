/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc125/submissions/45930150
 * Submitted at: 2023-09-25 09:37:56
 * Problem URL: https://atcoder.jp/contests/arc125/tasks/arc125_a
 * Result: AC
 * Execution Time: 15 ms
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

    ll n, m; cin >> n >> m;
    vector<ll> s(n), t(m);
    set<ll> st;
    rep(i,n) {
        cin >> s[i];
        st.insert(s[i]);
    }
    rep(i,m) {
        cin >> t[i];
        if( !st.count(t[i]) ) return cout << -1 << endl, 0;
    }
    bool f = true;
    rep(i,m-1) f &= (t[i] == t[i+1]);
    f &= (s[0] == t[0]);
    if( f ) return cout << m << endl, 0;

    ll cand = 1e9;
    rep(i,n) {
        if( s[0] != s[i] ) {
            cand = min(cand, i-1);
            break;
        }
    }
    for(ll i=n-1;i>=0;i--) {
        if( s[0] != s[i] ) {
            cand = min(cand, n-i-1);
            break;
        }
    }
    ll ans = cand, now = s[0];
    rep(i,m) {
        if( now == t[i] ) ans++;
        else {
            ans += 2;
            now = 1-now;
        }
    }
    cout << ans << endl;
    
    return 0;
}