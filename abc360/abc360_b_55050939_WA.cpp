/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55050939
 * Submitted at: 2024-06-30 21:04:42
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_b
 * Result: WA
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
    reps(w, 1, s.size()-1) {
        reps(c, 1, w+1) {
            string u = "";
            for(ll i = c-1; i < s.size(); i += c) u += s[i];
            if(u == t) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    
    return 0;
}