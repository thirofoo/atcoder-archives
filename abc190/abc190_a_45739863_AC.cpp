/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/45739863
 * Submitted at: 2023-09-20 09:15:32
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_a
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
    cout << ( ( (c == 0 && a > b) || (c == 1 && a >= b) ) ? "Takahashi" : "Aoki" ) << endl;
    
    return 0;
}