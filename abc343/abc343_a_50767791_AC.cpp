/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50767791
 * Submitted at: 2024-03-02 21:00:58
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b; cin >> a >> b;
    reps(i,0,10) {
        if( a+b == i ) continue;
        cout << i << endl;
        break;
    }
    
    return 0;
}