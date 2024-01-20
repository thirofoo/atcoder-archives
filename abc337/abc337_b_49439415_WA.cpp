/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc337/submissions/49439415
 * Submitted at: 2024-01-20 21:04:09
 * Problem URL: https://atcoder.jp/contests/abc337/tasks/abc337_b
 * Result: WA
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
    bool fa = false, fb = false, fc = false;
    rep(i,s.size()) {
        if(s[i] == 'C') {
            if( fa && fb ) fc = true;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
        if(s[i] == 'B') {
            if( fa && !fc) fb = true;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
        if(s[i] == 'A') {
            if( !fb && !fc) fa = true;
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}