/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc091/submissions/45783431
 * Submitted at: 2023-09-22 09:12:47
 * Problem URL: https://atcoder.jp/contests/abc091/tasks/abc091_a
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
    
    ll a, b, c; cin >> a >> b >> c;
    cout << ( a+b >= c ? "Yes" : "No" ) << endl;
    
    return 0;
}