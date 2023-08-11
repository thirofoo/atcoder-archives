/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc198/submissions/44445954
 * Submitted at: 2023-08-11 09:12:07
 * Problem URL: https://atcoder.jp/contests/abc198/tasks/abc198_b
 * Result: AC
 * Execution Time: 8 ms
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
    
    string n; cin >> n;
    while( !n.empty() && n.back() == '0' ) n.pop_back();
    for(ll i=0;i<n.size();i++) {
        if( n.size()-1-i <= i ) break;
        if( n[i] != n[n.size()-1-i] ) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}