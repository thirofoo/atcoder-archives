/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc193/submissions/45762161
 * Submitted at: 2023-09-21 09:25:16
 * Problem URL: https://atcoder.jp/contests/abc193/tasks/abc193_c
 * Result: AC
 * Execution Time: 17 ms
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
    ll ans = 0;
    set<ll> st;
    for(ll i=2;i<=sqrt(n)+5;i++) {
        ll now = i*i;
        while( now <= n ) {
            if( !st.count(now) ) ans++;
            st.insert(now);
            now *= i;
        }
    }
    cout << n-ans << endl;
    
    return 0;
}