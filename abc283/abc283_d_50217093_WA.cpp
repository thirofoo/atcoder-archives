/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/50217093
 * Submitted at: 2024-02-12 09:29:14
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: WA
 * Execution Time: 2211 ms
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
    auto dfs = [&](auto self, ll idx) -> void {
        bool res = true;
        for(ll i=idx; i<s.size(); i++) {
            if( s[i] == '(' ) self(self,i+1);
            else if( s[i] == ')' ) return st.clear();
            else {
                if( st.count(s[i]) ) f = false;
                st.insert(s[i]);
            }
        }
        return;
    };
    dfs(dfs,0);
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}