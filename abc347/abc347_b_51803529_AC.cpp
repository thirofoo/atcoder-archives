/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc347/submissions/51803529
 * Submitted at: 2024-03-30 21:02:33
 * Problem URL: https://atcoder.jp/contests/abc347/tasks/abc347_b
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    set<string> st;
    rep(i,s.size()) reps(j,i,s.size()) {
        string t = "";
        reps(k,i,j+1) t += s[k];
        st.insert(t);
    }
    cout << st.size() << '\n';
    
    return 0;
}