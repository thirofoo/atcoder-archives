/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49444657
 * Submitted at: 2024-01-20 21:07:10
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_b
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
    string abc = "ABC";
    ll idx = 0;
    rep(i,s.size()) {
        while( idx < 3 && s[i] != abc[idx] ) idx++;
        if(idx == 3) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}