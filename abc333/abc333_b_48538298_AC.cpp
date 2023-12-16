/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc333/submissions/48538298
 * Submitted at: 2023-12-16 21:02:37
 * Problem URL: https://atcoder.jp/contests/abc333/tasks/abc333_b
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

set<string> st = {"AB","BA","BC","CB","CD","DC","DE","ED","EA","AE"};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    cout << ( st.count(s) == st.count(t) ? "Yes" : "No" ) << endl;
    
    return 0;
}