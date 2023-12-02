/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48104373
 * Submitted at: 2023-12-02 21:06:45
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_b
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n, s, m, l; cin >> n >> s >> m >> l;
    ll ans = 1e16;
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            for(int k=0; k<=100; k++) {
                if( 6*i+8*j+12*k >= n ) ans = min(ans, s*i+m*j+k*l);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}