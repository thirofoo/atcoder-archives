/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc038/submissions/46473397
 * Submitted at: 2023-10-12 18:23:31
 * Problem URL: https://atcoder.jp/contests/abc038/tasks/abc038_b
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
    
    ll h1,w1,h2,w2; cin >> h1 >> w1 >> h2 >> w2;
    cout << ( ( (h1 == h2 || w1 == w2) || (h1 == w2 || h2 == w1) ) ? "YES" : "NO" ) << endl;
    
    return 0;
}