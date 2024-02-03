/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49913675
 * Submitted at: 2024-02-03 21:01:53
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_a
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s, ans = ""; cin >> s;
    reverse(s.begin(), s.end());
    rep(i, s.size()) {
        if( s[i] == '.' ) break;
        ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
    return 0;
}