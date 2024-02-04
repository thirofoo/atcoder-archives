/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc171/submissions/50004176
 * Submitted at: 2024-02-04 21:17:49
 * Problem URL: https://atcoder.jp/contests/arc171/tasks/arc171_a
 * Result: AC
 * Execution Time: 107 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--) {
        ll n, a, b; cin >> n >> a >> b;
        if( n < a ) {
            cout << "No" << endl;
            continue;
        }
        ll rest;
        if( a >= n/2 ) rest = (n-a)*(n-a);
        else rest = n*((n+1)/2) - ((n+1)/2)*a;
        cout << ( b <= rest ? "Yes" : "No" ) << endl;
    }
    
    return 0;
}