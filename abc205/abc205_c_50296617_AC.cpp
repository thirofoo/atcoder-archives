/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc205/submissions/50296617
 * Submitted at: 2024-02-16 09:11:30
 * Problem URL: https://atcoder.jp/contests/abc205/tasks/abc205_c
 * Result: AC
 * Execution Time: 2 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    
    ll a, b, c; cin >> a >> b >> c;
    if( c%2 == 0 ) cout << (abs(a) == abs(b) ? "=" : (abs(a) > abs(b) ? ">" : "<")) << endl;
    else cout << (a == b ? "=" : (a > b ? ">" : "<")) << endl;
    
    return 0;
}