/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/45762424
 * Submitted at: 2023-09-21 09:46:25
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_c
 * Result: AC
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
    x = abs(x);
    // オーバーフロー注意
    if( x/d-k >= 0 ) cout << abs(x-k*d) << endl;
    else {
        if( (k - x/d)%2 == 0 ) cout << x%d << endl;
        else cout << d-x%d << endl;
    }
    
    return 0;
}