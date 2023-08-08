/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc196/submissions/44374932
 * Submitted at: 2023-08-08 10:15:42
 * Problem URL: https://atcoder.jp/contests/abc196/tasks/abc196_e
 * Result: WA
 * Execution Time: 357 ms
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
    ll left = -1e16, right = 1e16, add = 0;
    rep(i,n) {
        ll a,t; cin >> a >> t;
        if( t == 1 ) {
            left += a;
            right += a;
            add += a;
        }
        else if( t == 2 ) left = max(left,a);
        else right = min(right,a);
    }
    ll q; cin >> q;
    while(q--) {
        ll x; cin >> x;
        cout << min(right,max(left,x+add)) << endl;
    }
    
    return 0;
}