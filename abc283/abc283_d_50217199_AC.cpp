/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/50217199
 * Submitted at: 2024-02-12 09:45:35
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_d
 * Result: AC
 * Execution Time: 28 ms
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
        // cerr << "idx: " << idx << endl;
        bool res = true;
        ll start = idx;
        set<ll> tst;
        while( idx < s.size() ) {
            if( s[idx] == '(' ) idx++, self(self);
            else if( s[idx] == ')' ) {
                for(auto c : tst) {
                    if( !st.count(c) ) f = false;
                    else st.erase(st.find(c));
                    // cerr << "erase: " << (char)c << endl;
                }
                idx++;
                return;
            }
            else {
                if( st.count(s[idx]) ) f = false;
                st.insert(s[idx]);
                tst.insert(s[idx]);
                idx++;
            }
            // cerr << "idx: " << idx << endl;
        }
    };
    dfs(dfs);
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}

// NG ケース : (a(()a))
