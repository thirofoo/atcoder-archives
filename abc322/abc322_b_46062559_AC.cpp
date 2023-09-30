/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46062559
 * Submitted at: 2023-09-30 21:03:59
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_b
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
    
    ll n, m; string s, t; cin >> n >> m >> s >> t;
    bool f1 = true, f2 = true;
    rep(i,n) f1 &= (s[i] == t[i]);
    rep(i,n) f2 &= (s[n-i-1] == t[m-i-1]);

    if( f1 && f2 ) cout << 0 << endl;
    else if( f1 ) cout << 1 << endl;
    else if( f2 ) cout << 2 << endl;
    else cout << 3 << endl;
    
    return 0;
}