/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc166/submissions/50677857
 * Submitted at: 2024-02-27 16:50:58
 * Problem URL: https://atcoder.jp/contests/abc166/tasks/abc166_d
 * Result: AC
 * Execution Time: 6 ms
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
    
    ll X; cin >> X;
    reps(A,-1000,1000) reps(B,-1000,1000) if( A*A*A*A*A-B*B*B*B*B == X ) return cout << A << " " << B << endl, 0;
    
    return 0;
}