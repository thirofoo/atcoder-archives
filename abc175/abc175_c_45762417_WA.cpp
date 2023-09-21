/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/45762417
 * Submitted at: 2023-09-21 09:45:17
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_c
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
    
    ll x, k, d; cin >> x >> k >> d;
    x = abs(x);
    if( x-k*d >= 0 ) cout << abs(x-k*d) << endl;
    else {
        if( (k - x/d)%2 == 0 ) cout << x%d << endl;
        else cout << d-x%d << endl;
    }
    
    return 0;
}