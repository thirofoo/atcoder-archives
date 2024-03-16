/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc345/submissions/51282744
 * Submitted at: 2024-03-16 21:05:22
 * Problem URL: https://atcoder.jp/contests/abc345/tasks/abc345_b
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
    
    ll x; cin >> x;
    if( x >= 0 ) x = (x%10 == 0 ? 0 : 1) + x/10;
    else x = x/10;
    cout << x << endl;
    
    return 0;
}