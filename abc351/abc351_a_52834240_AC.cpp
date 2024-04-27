/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc351/submissions/52834240
 * Submitted at: 2024-04-27 21:01:23
 * Problem URL: https://atcoder.jp/contests/abc351/tasks/abc351_a
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
    
    vector<ll> a(9), b(8);
    ll at = 0, bt = 0;
    rep(i, 9) {
        cin >> a[i];
        at += a[i];
    }
    rep(i, 8) {
        cin >> b[i];
        bt += b[i];
    }
    cout << at-bt+1 << endl;
    
    return 0;
}