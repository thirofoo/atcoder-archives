/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/m-solutions2020/submissions/50916549
 * Submitted at: 2024-03-05 13:17:03
 * Problem URL: https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c, k; cin >> a >> b >> c >> k;
    while( b <= a ) {
        b *= 2;
        k--;
    }
    while( c <= b ) {
        c *= 2;
        k--;
    }
    if( k >= 0 ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}