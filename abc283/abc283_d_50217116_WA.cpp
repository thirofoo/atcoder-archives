/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/50217116
 * Submitted at: 2024-02-12 09:33:36
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: WA
 * Execution Time: 14 ms
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
    set<char> st;
    bool f = true;
    ll idx = 0;
    auto dfs = [&](auto self) -> void {
        bool res = true;
        while( idx < s.size() ) {
            if( s[idx] == '(' ) idx++, self(self);
            else if( s[idx] == ')' ) {
                idx++, st.clear();
                return;
            }
            else {
                if( st.count(s[idx]) ) f = false;
                st.insert(s[idx]);
                idx++;
            }
        }
    };
    dfs(dfs);
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}