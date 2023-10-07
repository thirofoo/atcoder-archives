/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc323/submissions/46285039
 * Submitted at: 2023-10-07 21:04:14
 * Problem URL: https://atcoder.jp/contests/abc323/tasks/abc323_a
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
    
    string s; cin >> s;
    bool f = true;
    rep(i,s.size()) {
        if( i+1 < 2 || i+1 > 16 || (i+1)%2 == 1 ) continue;
        f &= (s[i] == '0');
    }
    cout << ( f ? "Yes" : "No" ) << endl;
    
    return 0;
}