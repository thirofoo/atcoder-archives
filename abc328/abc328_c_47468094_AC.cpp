/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47468094
 * Submitted at: 2023-11-11 21:14:52
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_c
 * Result: AC
 * Execution Time: 320 ms
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
    
    ll n, q; string s; cin >> n >> q >> s;
    vector<ll> rui(n,0);
    rep(i,n-1) rui[i+1] = rui[i] + (s[i] == s[i+1]);
    while( q-- ) {
        ll l, r; cin >> l >> r;
        l--; r--;
        cout << rui[r] - rui[l] << endl;
    }
    
    return 0;
}