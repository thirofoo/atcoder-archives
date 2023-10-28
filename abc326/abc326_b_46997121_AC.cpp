/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc326/submissions/46997121
 * Submitted at: 2023-10-28 21:04:16
 * Problem URL: https://atcoder.jp/contests/abc326/tasks/abc326_b
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
    for(int i=n; i<1000; i++) {
        ll e1 = i%10, e2 = i%100, e3 = i;
        e2 -= e1, e3 -= e1, e3 -= e2;
        e2 /= 10, e3 /= 100;
        if( e3*e2 == e1 ) return cout << i << endl, 0;
    }
    
    return 0;
}