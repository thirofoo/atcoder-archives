/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53086348
 * Submitted at: 2024-05-04 21:04:06
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_b
 * Result: AC
 * Execution Time: 11 ms
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
    
    string s, t; cin >> s >> t;
    ll si = 0;
    rep(i,t.size()) {
        if( t[i] == s[si] ) {
            cout << i+1 << " ";
            si++;
        }
        if( si >= s.size() ) break;
    }
    cout << endl;
    
    return 0;
}