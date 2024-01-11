/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc204/submissions/49216056
 * Submitted at: 2024-01-11 18:52:15
 * Problem URL: https://atcoder.jp/contests/abc204/tasks/abc204_a
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
    
    ll x, y; cin >> x >> y;
    if( x == y ) cout << x << endl;
    else cout << 3-x-y << endl;
    
    return 0;
}