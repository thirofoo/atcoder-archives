/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49691165
 * Submitted at: 2024-01-27 21:01:08
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_a
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
    f &= ('A' <= s[0] && s[0] <= 'Z');
    for(ll i=1; i<s.size(); i++) f &= ('a' <= s[i] && s[i] <= 'z');
    cout << (f ? "Yes" : "No") << endl;
    
    return 0;
}