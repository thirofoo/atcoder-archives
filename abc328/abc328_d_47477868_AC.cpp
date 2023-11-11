/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47477868
 * Submitted at: 2023-11-11 21:30:17
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_d
 * Result: AC
 * Execution Time: 4 ms
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
    
    string s, ans = ""; cin >> s;
    deque<char> st;
    rep(i,s.size()) {
        st.push_back(s[i]);
        if( st.size() >= 3 ) {
            ll size = st.size()-1;
            if( st[size] == 'C' && st[size-1] == 'B' && st[size-2] == 'A' ) {
                st.pop_back(); st.pop_back(); st.pop_back();
            }
        }
    }
    while( !st.empty() ) {
        cout << st.front();
        st.pop_front();
    }
    cout << endl;

    return 0;
}