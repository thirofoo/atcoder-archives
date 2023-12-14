/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/48483088
 * Submitted at: 2023-12-14 14:04:39
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_d
 * Result: WA
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
    
    ll w; cin >> w;
    rep(i,100) cout << i+1 << endl;
    rep(i,100) cout << (i+1)*100 << endl;
    rep(i,100) cout << (i+1)*10000 << endl;
    
    return 0;
}