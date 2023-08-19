/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44708446
 * Submitted at: 2023-08-19 21:01:30
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_a
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
    rep(i,s.size()) {
        if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'  ) continue;
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}