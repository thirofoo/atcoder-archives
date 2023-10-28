/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/46991961
 * Submitted at: 2023-10-28 21:01:48
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_a
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
    if( -3 <= y-x && y-x <= 2 ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}