/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/48483111
 * Submitted at: 2023-12-14 14:05:29
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_d
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
    
    ll w; cin >> w;
    cout << 300 << endl;
    rep(i,100) cout << i+1 << " ";
    rep(i,100) cout << (i+1)*100 << " ";
    rep(i,100) cout << (i+1)*10000 << " ";
    cout << endl;
    
    return 0;
}