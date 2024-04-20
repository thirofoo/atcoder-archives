/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc350/submissions/52547827
 * Submitted at: 2024-04-20 21:03:31
 * Problem URL: https://atcoder.jp/contests/abc350/tasks/abc350_a
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
    
    string s; cin >> s;
    ll num = 0;
    num *= 10;
    num += s[3]-'0';
    num *= 10;
    num += s[4]-'0';
    num *= 10;
    num += s[5]-'0';
    if( 1 <= num && num <= 349 && num != 316 ) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    
    return 0;
}