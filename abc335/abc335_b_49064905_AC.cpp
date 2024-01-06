/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49064905
 * Submitted at: 2024-01-06 21:02:30
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_b
 * Result: AC
 * Execution Time: 3 ms
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
    for(ll x=0; x<=n; x++) {
        for(ll y=0; y<=n; y++) {
            for(ll z=0; z<=n; z++) {
                if( x+y+z <= n ) cout << x << " " << y << " " << z << endl;
            }
        }
    }
    
    return 0;
}