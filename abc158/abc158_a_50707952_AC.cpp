/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc158/submissions/50707952
 * Submitted at: 2024-02-28 23:16:56
 * Problem URL: https://atcoder.jp/contests/abc158/tasks/abc158_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    string s; cin >> s;
    rep(i,s.size()-1) if( s[i] != s[i+1] ) return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    
    return 0;
}