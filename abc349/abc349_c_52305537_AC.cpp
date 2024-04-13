/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52305537
 * Submitted at: 2024-04-13 21:08:46
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_c
 * Result: AC
 * Execution Time: 2 ms
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
    rep(i,s.size()) s[i] = s[i]-'a'+'A';
    cerr << s << endl;
    int idx = 0;
    rep(i,s.size()) {
        if( s[i] == t[idx] ) idx++;
        if( idx == t.size() ) return cout << "Yes" << endl, 0;
    }
    if( idx == 2 && t.back() == 'X' ) return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    
    return 0;
}