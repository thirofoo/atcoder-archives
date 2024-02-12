/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/50217022
 * Submitted at: 2024-02-12 09:19:18
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: WA
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    stack<int> st1;
    set<char> st2;
    rep(i,s.size()) {
        if(s[i] == '(') st1.push(i);
        else if( s[i] == ')' ) st2.clear();
        else {
            if( st2.count(s[i]) ) {
                cout << "No" << "\n";
                return 0;
            }
            st2.insert(s[i]);
        }
    }
    cout << "Yes" << "\n";    
    return 0;
}