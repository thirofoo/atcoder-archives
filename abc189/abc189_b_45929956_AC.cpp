/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/45929956
 * Submitted at: 2023-09-25 09:22:45
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_b
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
    
    int n,  x; cin >> n >> x;
    int total = 0;
    rep(i,n) {
        int v, p; cin >> v >> p;
        total += v*p;
        if( total > x*100 ) {
            return cout << i+1 << endl, 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}