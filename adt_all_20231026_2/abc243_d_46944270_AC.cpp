/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46944270
 * Submitted at: 2023-10-26 18:55:32
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc243_d
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n, x; string s; cin >> n >> x >> s;
    ll cnt = 0;
    rep(i,n) {
        if( s[i] == 'U' ) {
            if( cnt ) cnt--;
            else x /= 2;
        }
        else if( s[i] == 'L' ) {
            if( x > 1e18 ) cnt++;
            else x = 2*x;
        }
        else {
            if( x > 1e18 ) cnt++;
            else x = 2*x + 1;
        }
    }
    cout << x << endl;
    
    return 0;
}