/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/50511747
 * Submitted at: 2024-02-22 17:22:07
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: AC
 * Execution Time: 16 ms
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
    stack<char> st;
    multiset<char> ms;
    for(auto ch: s) {
        if( ch == ')' ) {
            while( !st.empty() && st.top() != '(' ) {
                ms.erase(ms.find(st.top()));
                st.pop();
            }
            if( st.empty() ) return cout << "No" << endl, 0;
            st.pop();
        }
        else if( ch != '(' ) {
            auto itr = ms.find(ch);
            if( itr == ms.end() ) ms.insert(ch);
            else return cout << "No" << endl, 0;
            st.push(ch);
        }
        else st.push(ch);
    }
    cout << "Yes" << endl;
    
    return 0;
}