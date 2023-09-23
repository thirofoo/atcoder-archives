/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/45818383
 * Submitted at: 2023-09-23 21:02:18
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_a
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
    
    ll n; cin >> n;
    ll now = n%10;
    n /= 10;
    while( n ) {
        if( now >= n%10 ) {
            cout << "No" << endl;
            return 0;
        }
        now = n%10;
        n /= 10;
    }
    cout << "Yes" << endl;
    
    return 0;
}