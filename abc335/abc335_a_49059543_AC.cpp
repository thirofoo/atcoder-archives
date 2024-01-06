/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc335/submissions/49059543
 * Submitted at: 2024-01-06 21:00:35
 * Problem URL: https://atcoder.jp/contests/abc335/tasks/abc335_a
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
    s[s.size()-1] = '4';
    cout << s << endl;
    
    return 0;
}