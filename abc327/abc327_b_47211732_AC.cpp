/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc327/submissions/47211732
 * Submitted at: 2023-11-04 21:02:56
 * Problem URL: https://atcoder.jp/contests/abc327/tasks/abc327_b
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
    
    ll b; cin >> b;
    rep(i,20) {
        ll cand = 1;
        rep(j,i+1) cand *= i+1;
        if( b == cand ) return cout << i+1 << endl, 0;
    }
    cout << -1 << endl;
    
    return 0;
}