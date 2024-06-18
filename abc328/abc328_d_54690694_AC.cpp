/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/54690694
 * Submitted at: 2024-06-18 18:31:09
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_d
 * Result: AC
 * Execution Time: 5 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    stack<char> st;
    rep(i, s.size()) {
        st.push(s[i]);
        while(st.size() >= 3) {
            char c1 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            char c3 = st.top(); st.pop();
            if(!(c1 == 'C' && c2 == 'B' && c3 == 'A')) {
                st.push(c3);
                st.push(c2);
                st.push(c1);
                break;
            }
        }
    }
    vector<char> v;
    while(!st.empty()) {
        v.emplace_back(st.top());
        st.pop();
    }
    reverse(v.begin(), v.end());
    rep(i, v.size()) cout << v[i];
    cout << endl;
    
    return 0;
}