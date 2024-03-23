/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc346/submissions/51548847
 * Submitted at: 2024-03-23 21:03:26
 * Problem URL: https://atcoder.jp/contests/abc346/tasks/abc346_b
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
    
    ll w, b; cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    string piano = "";
    rep(i,300) piano += s;
    rep(i,3000) {
        ll cb = 0, cw = 0;
        rep(j,w+b) {
            if(piano[i+j] == 'b') cb++;
            else cw++;
        }
        if(cb == b && cw == w) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}