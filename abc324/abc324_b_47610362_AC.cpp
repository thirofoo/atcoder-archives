/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47610362
 * Submitted at: 2023-11-16 13:25:12
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_b
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
    while( n%2 == 0 ) n /= 2;
    while( n%3 == 0 ) n /= 3;
    cout << (n == 1 ? "Yes" : "No") << endl;
    
    return 0;
}