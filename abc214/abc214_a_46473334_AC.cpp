/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc214/submissions/46473334
 * Submitted at: 2023-10-12 18:20:53
 * Problem URL: https://atcoder.jp/contests/abc214/tasks/abc214_a
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
    if( n <= 125 ) cout << 4 << endl;
    else if( n <= 211 ) cout << 6 << endl;
    else cout << 8 << endl;
    
    return 0;
}