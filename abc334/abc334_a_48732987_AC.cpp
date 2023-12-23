/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc334/submissions/48732987
 * Submitted at: 2023-12-23 21:00:45
 * Problem URL: https://atcoder.jp/contests/abc334/tasks/abc334_a
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
    
    ll b, g; cin >> b >> g;
    cout << (b > g ? "Bat" : "Glove") << endl;
    
    return 0;
}