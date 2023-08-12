/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44489419
 * Submitted at: 2023-08-12 21:02:00
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_a
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

string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    n += 2;
    rep(i,n) cout << pi[i];
    cout << endl;
    
    return 0;
}