/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/45762371
 * Submitted at: 2023-09-21 09:41:00
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_c
 * Result: WA
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
    
    ll x, k, d; cin >> x >> k >> d;
    if( x >= 0 && x-k*d >= 0 ) return cout << abs(x-k*d) << endl, 0;
    if( x < 0 && x+k*d < 0 ) return cout << abs(x+k*d) << endl, 0;

    ll ans = 1e16;
    ll time = x/d;
    if( time%2 == 0 ) ans = min(ans, x - time*d);
    else ans = min(ans, x - (time+1)*d);
    cout << abs(ans) << endl;
    
    return 0;
}