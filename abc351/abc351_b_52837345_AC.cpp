/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52837345
 * Submitted at: 2024-04-27 21:02:47
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_b
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
    
    ll n; cin >> n;
    vector<string> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) rep(j,n) if( a[i][j] != b[i][j] ) return cout << i+1 << " " << j+1 << endl, 0;

    return 0;
}