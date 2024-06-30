/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55052909
 * Submitted at: 2024-06-30 21:06:44
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    string s, t; cin >> s >> t;
    reps(w, 1, s.size()) {
        rep(c, w) {
            string u = "";
            for(ll i = c; i < s.size(); i += w) u += s[i];
            if(u == t) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    
    return 0;
}