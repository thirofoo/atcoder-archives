/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48101635
 * Submitted at: 2023-12-02 21:04:44
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_a
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
    
    ll M, D, y, m, d; cin >> M >> D >> y >> m >> d;
    d++;
    if( d > D ) d = 1, m++;
    if( m > M ) m = 1, y++;
    cout << y << " " << m << " " << d << endl;
    
    return 0;
}