/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc332/submissions/48371821
 * Submitted at: 2023-12-10 21:08:54
 * Problem URL: https://atcoder.jp/contests/abc332/tasks/abc332_b
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
    
    ll k, g, m; cin >> k >> g >> m;
    ll gv = 0, mv = 0;
    rep(i,k) {
        if( gv == g ) gv = 0;
        else if( mv == 0 ) mv = m;
        else {
            ll tmp = min(g-gv,mv);
            gv += tmp;
            mv -= tmp;
        }
        // cerr << gv << " " << mv << endl;
    }
    cout << gv << " " << mv << endl;
    
    return 0;
}