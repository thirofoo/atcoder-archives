/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc322/submissions/46057939
 * Submitted at: 2023-09-30 21:01:33
 * Problem URL: https://atcoder.jp/contests/abc322/tasks/abc322_a
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
    
    ll n; string s; cin >> n >> s;
    rep(i,n-2) {
        if( s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C' ) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}