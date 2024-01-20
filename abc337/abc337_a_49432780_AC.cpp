/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49432780
 * Submitted at: 2024-01-20 21:01:00
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_a
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
    
    ll n; cin >> n;
    ll tx = 0, ty = 0;
    rep(i,n) {
        ll x, y; cin >> x >> y;
        tx += x;
        ty += y;
    }
    if( tx == ty ) cout << "Draw" << endl;
    else if( tx > ty ) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    
    return 0;
}