/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc130/submissions/45717670
 * Submitted at: 2023-09-19 09:44:06
 * Problem URL: https://atcoder.jp/contests/abc130/tasks/abc130_c
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
    cout << setprecision(10) << fixed;
    
    ll w, h, x, y; cin >> w >> h >> x >> y;
    cout << w*h/2 << " " << !(x == 0 || x == h || y == 0 || y == w) << endl;
    
    return 0;
}